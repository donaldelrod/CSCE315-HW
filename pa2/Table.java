import java.util.*;
import java.lang.*;
import java.io.Serializable;


public class Table implements Serializable {
	
	private static final long serialVersionUID = 1L;
	
	public String name;					//name of table
	public ArrayList<TypedAttribute> cols;	//the names and types of columns
	public ArrayList<TypedAttribute[]> tuples;  //all the tuples with data corresponding to cols
	public ArrayList<String> pks;		//the primary keys for this table
	//can maybe get rid of this last arraylist
	
	Table(String ntableName, ArrayList<TypedAttribute> ncols, ArrayList<String> npks) {
		this.name = ntableName;
		this.cols = ncols;
		this.pks = npks;
		this.tuples = new ArrayList<TypedAttribute[]>();
	}
	
	Table(ArrayList<TypedAttribute> ncols, ArrayList<TypedAttribute[]> tups, String autoName) {
		name = autoName;
		cols = ncols;
		tuples = tups;
		pks = null;
	}
	
	Table() {
		
	}
	
	public void addTuple(TypedAttribute[] tuple) {
		tuples.add(tuple);
	}
	
	public Object getColFromTuple(int rowIndex, int colIndex) {
		return tuples.get(rowIndex)[colIndex];
	}
	
	public String stringifyTuple(int rowIndex) {
		Object[] tuple = tuples.get(rowIndex);
		String s = "";
		for (Object o : tuple) {
			s += o.toString() + '\t';
		}
		return s;
	}
	
	public int numRows() {
		return this.tuples.size();
	}
	
	public int numCols() {
		return this.cols.size();
	}
	
	public int getColIndex(String colName) {
		for (int i = 0; i < cols.size(); i++) {
			if (cols.get(i).name.toLowerCase().equals(colName.toLowerCase()))
				return i;
		}
		return -1;
	}
	
	public Type getColType(int colIndex) {
		return cols.get(colIndex).val;
	}
	
	public boolean dropRow(int rowIndex) {
		if (rowIndex > tuples.size())
			return false;
		tuples.remove(rowIndex);
		return true;
	}
	
	public void updateRow(int rowIndex, ArrayList<Integer> colIndexes, ArrayList<TypedAttribute> newColVals) {
		//might have to add pk checking here, we'll see
		
		for (int i = 0; i < colIndexes.size(); i++)
			tuples.get(rowIndex)[colIndexes.get(i)] = newColVals.get(i);
	}
	
	/**
	 * Convertd the column names and types into a string that cna be printed
	 * 
	 * FINISHED
	 */
	public String getHeaderString() {
		String s = "";
		//second pass is for the type of the header columns
		for (int i = 0; i < 2; i++) {
			//this goes through the columns and adds either the column name or type to the string
			for (int j = 0; j < cols.size(); j++) {
				//first time through, grab the name
				if (i == 0)
					s += String.format("%-20s", "|"+cols.get(j).name);
				//second time through, grab the type
				else
					s += String.format("%-20s", "|"+cols.get(j).val.toString());
			}
			s += "|\n";
		}
		return s;
	}
	
	/**
	 * Gets the header names of the specified column and returns it as a string
	 * 
	 * FINISHED
	 */
	public String getHeaderString(ArrayList<Integer> colIndexes) {
		String s = "";
		//second pass is for the type of the header columns
		for (int i = 0; i < 2; i++) {
			//this goes through the columns and adds either the column name or type to the string
			for (int j = 0; j < cols.size(); j++) {
				//first time through, grab the name if the column is in the list of columns to print
				if (i == 0 && colIndexes.contains(j))
					s += String.format("%-20s", "|"+cols.get(j).name);
				//second time through, grab the type if the column is in the list of columns given
				else if (i == 1 && colIndexes.contains(j))
					s += String.format("%-20s", "|"+cols.get(j).val.toString());
			}
			s += "|\n";
		}
		return s;
	}
	
	/**
	 * Converts the tuple at rowIndex to a string to be printed
	 * 
	 * FINISHED
	 */
	public String getRowString(int rowIndex) {
		String s = "";
		TypedAttribute[] tuple = tuples.get(rowIndex);
		for (TypedAttribute ta : tuple) {
			s += String.format("%-20s", "|"+ta.val.toStringVal());
		}
		return s+"|";
	}
	
	/**
	 * Public static method for converting a set of tuples to a string
	 * 
	 * FINISHED
	 */
	public static String tupleString(ArrayList<TypedAttribute[]> tup) {
		String s = "";
		for (TypedAttribute[] ta : tup) {
			for (TypedAttribute ta1 : ta)
				s += String.format("%-20s", ta1.val.toStringVal());
			s += "\n";
		}
		return s;
	}
	
	/**
	 * Gets the column indexes of all the primary keys for the table
	 * 
	 * FINISHED
	 */
	public int[] getPKColIndexes() {
		int[] indexes = new int[pks.size()];
		int indexToIndexes = 0;
		for (String pkcol : pks) {
			int tempIndex = this.getColIndex(pkcol);
			if (tempIndex != -1)
				indexes[indexToIndexes++] = tempIndex;
		}
		
		return indexes;
	}
	
	/**
	 * Checks to see if there is a primary key violation between
	 * the table and the new tuple being added
	 * 
	 * FINISHED
	 */
	public boolean checkForPKViolation(TypedAttribute[] newTuple) {
		if (tuples.size() == 0)
			return false;
		
		int[] pkIndexes = this.getPKColIndexes();
		
		//this loop iterates through all the tuples to see if the primary keys 
		//of the new tuple do not conflict with existing tuples
		for (TypedAttribute[] ta : tuples) {
			int numPK = pkIndexes.length;
			
			//this loop goes through all the columns which are primary keys
			//in the existing table entries, and if the new tuple matches
			//the primary key of an existing tuple, it is not added
			for (int i = 0; i < numPK; i++) {
				
				//this checks the column of the temporary tuple variable
				//against the new tuple. If any of the pks do not match
				//the current tuple we are checking it against, it will
				//continue down the list of tuples until it reaches the 
				//end or returns
				if (ta[pkIndexes[i]] != newTuple[pkIndexes[i]])
					break;
				
				//if it made it through all comparisons and did not break
				//from the inner for, then all pks must have matched and
				//this tuple cannot be added
				if (i == numPK - 1)
					return true;
			}
		}
		return false;
	}
	
	/**
	 * Returns all columns from the table with the specified indexes
	 */
	public ArrayList<TypedAttribute[]> getCols(ArrayList<Integer> colIndexes) {
		int newNumCols = colIndexes.size();
		ArrayList<TypedAttribute[]> selected = new ArrayList<TypedAttribute[]>();
		for (TypedAttribute[] ta : tuples) {
			int cnt = 0;
			TypedAttribute[] newRow = new TypedAttribute[newNumCols];
			for (Integer i : colIndexes) {
				newRow[cnt++] = ta[i];
			}
			selected.add(newRow);
		}
		return selected;
	}
	
	/**
	 * Returns the column headers at the specified indexes
	 */
	public ArrayList<TypedAttribute> getColHeaders(ArrayList<Integer> colIndexes) {
		ArrayList<TypedAttribute> newHeaders = new ArrayList<TypedAttribute>();
		for (int ind : colIndexes) 
			newHeaders.add(cols.get(ind));
		return newHeaders;
	}
	
	public boolean equals(Table t2) {
		if (t2.cols.size() != this.cols.size())
			return false;
		int numCols = this.cols.size();
		for (int i = 0; i < numCols; i++) {
			for (int j = 0; j < numCols; j++) {
				if (this.cols.get(i).equals(t2.cols.get(j))) {
					break;
				}
				
				if (j+1 == numCols)
					return false;
			}
		}
		return true;
		
	}
	
	public Table getClone() {
		try {
			return (Table)super.clone();
		} catch (Exception e) {return null;}
	}
}