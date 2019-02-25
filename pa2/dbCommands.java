import java.util.*;
import java.io.*;
//import Table.java;
//import Condition.java;

public class dbCommands {
	
	public static void exit() {
		System.exit(0);
	}
	
	public static void closeTable(Table t) {
		t = null;
	}
	
	public static Table openTable(String tablename) {
		try {
			FileInputStream dbFile = new FileInputStream("./" + tablename + ".db");
			ObjectInputStream objectIn = new ObjectInputStream(dbFile);
		    Object obj = objectIn.readObject();
		    objectIn.close();
		    return (Table)obj;
		    
		} catch (Exception ex) {
		    ex.printStackTrace();
		    return null;
		}
	}
	
	//I borrowed the format for this function from the following source
	//https://examples.javacodegeeks.com/core-java/io/fileoutputstream/how-to-write-an-object-to-file-in-java/
	public static void saveTable(Table t) {
		try {
			FileOutputStream dbFile = new FileOutputStream("./" + t.name + ".db");
	        ObjectOutputStream objectOut = new ObjectOutputStream(dbFile);
	        objectOut.writeObject(t);
	        objectOut.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.out.println("table didn\'t successfully save");
		}
	}
	
	/**
	 * Creates a Table object, and returns the newly made Table
	 * 
	 * FINISHED
	 */
	public static Table createTable(String tableName, ArrayList<TypedAttribute> cols, ArrayList<String> pks) {
		Table t = new Table(tableName, cols, pks);
		return t;
	}
	
	/**
	 * Updates a given tuple in the given table
	 * 
	 * FINISHED
	 */
	public static void updateTuple(Table t, ArrayList<TypedAttribute> cols, ArrayList<TypedAttribute> newCols, Condition c) {
		
		//gets the column name of the condition
		String colName = c.x.name;
		
		int numRows = t.numRows();
		
		ArrayList<Integer> indexesToUpdate = new ArrayList<Integer>();
		//gets the column index of the column the condition is on
		int colIndex = t.getColIndex(colName);
		
		//this iterates through the table's tuples and checks to see if the
		//individual tuples satisfy the condition
		for (int i = 0; i < numRows; i++) {			
			//this uses the values of the tuple's column that the condition
			//is being checked against to see if it meets the condition
			if (c.solve(t.tuples.get(i)[colIndex]))
				indexesToUpdate.add(i);
		}
		
		ArrayList<Integer> indexesColsToChange = new ArrayList<Integer>();
		
		for (TypedAttribute col : cols)
			indexesColsToChange.add(t.getColIndex(col.name));		
		
		for (int i = 0; i < indexesToUpdate.size(); i++) {
			t.updateRow(indexesToUpdate.get(i), indexesColsToChange, newCols);
		}
		
	}
	
	
	/**
	 * This function returns a Table from the given
	 * table that meet the given condition
	 * 
	 * FINISHED
	 */
	public static Table selection(Table t, Condition c) {
		
		String colName = c.x.name;
		
		int numRows = t.numRows();
		
		ArrayList<TypedAttribute[]> indexesToSelect = new ArrayList<TypedAttribute[]>();
		//gets the column index of the column the condition is on
		int colIndex = t.getColIndex(colName);
		
		//this iterates through the table's tuples and checks to see if the
		//individual tuples satisfy the condition
		for (int i = 0; i < numRows; i++) {			
			//this uses the values of the tuple's column that the condition
			//is being checked against to see if it meets the condition
			if (c.solve(t.tuples.get(i)[colIndex]))
				indexesToSelect.add(t.tuples.get(i));
		}
		
		return new Table(t.cols, indexesToSelect, "selection on " + t.name);
	}
	/**
	 * This function does a selection with a comparison instead of a condition
	 * 
	 * FINISHED
	 */
	public static Table selection(Table t, Comparison c) {
				
		ArrayList<String> colNames = c.getColNames();
		
		int numRows = t.numRows();
		
		ArrayList<TypedAttribute[]> tuplesToSelect = new ArrayList<TypedAttribute[]>();
		//gets the column index of the column the condition is on
		ArrayList<Integer> colIndexes = new ArrayList<Integer>();
		for (int i = 0; i < colNames.size(); i++)
			colIndexes.add(t.getColIndex(colNames.get(i)));
		
		//this iterates through the table's tuples and checks to see if the
		//individual tuples satisfy the condition
		for (int i = 0; i < numRows; i++) {
			//arrraylist that will hold all the values being checking in comparison
			ArrayList<TypedAttribute> tupleVals = new ArrayList<TypedAttribute>();
			
			//for each column that needs to be checked, the row values are extracted
			for (int j = 0; j < colIndexes.size(); j++)
				tupleVals.add(t.tuples.get(i)[colIndexes.get(j)]);
			
			//this uses the values of the tuple's column that the condition
			//is being checked against to see if it meets the condition
			if (c.solve(tupleVals))
				tuplesToSelect.add(t.tuples.get(i));
		}
		
		return new Table(t.cols, tuplesToSelect, "selection on " + t.name);
	}
	
	
	/**
	 * This function returns only the columns whose names are in the cols variable
	 * 
	 * FINISHED
	 */
	public static Table projectionS(Table t, ArrayList<String> cols) {
		ArrayList<Integer> colIndexes = new ArrayList<Integer>();
		//adds the indexes of the specified column names to the AL
		for (String s : cols)
			colIndexes.add(t.getColIndex(s));
		
		//this gets all the tuples in the table, but only with the specified column indexes
		return new Table(t.getColHeaders(colIndexes), t.getCols(colIndexes), "projection on " + t.name);
	}
	
	/**
	 * This function returns only the columns whose names are in the cols variable
	 */
	public static Table projectionI(Table t, ArrayList<Integer> colIndexes) {
		//this gets all the tuples in the table, but only with the specified column indexes
		return new Table(t.getColHeaders(colIndexes), t.getCols(colIndexes), "projection on " + t.name);
	}
	
	
	/**
	 * Takes two ArrayLists of tuples and returns their union
	 * 
	 * FINISHED
	 */
	public static Table union(Table t1, Table t2) {
		if (!t1.equals(t2)) {
			System.out.println("Sets are not compatible\nSet 1:\n");
			dbCommands.showTable(t1);
			System.out.println("Set 2:\n");
			dbCommands.showTable(t2);
			return null;
		}
		
		for (TypedAttribute[] ta : t2.tuples)
			t1.tuples.add(ta);
		t1.name = t1.name + " + " + t2.name;
		return t1;
	}
	
	/**
	 * Computes the set difference between 2 tables
	 * 
	 * FINISHED
	 */
	public static Table difference(Table t1, Table t2) {
		
		if (!t1.equals(t2)) {
			System.out.println("Sets are not compatible\nSet 1:\n");
			dbCommands.showTable(t1);
			System.out.println("Set 2:\n");
			dbCommands.showTable(t2);
			return null;
		}
		
		ArrayList<TypedAttribute[]> newTuples = new ArrayList<TypedAttribute[]>();
		
		int cnt1 = 0;
		for (TypedAttribute[] t1Tuple : t1.tuples) {
			boolean found = false;
			for (TypedAttribute[] t2Tuple : t2.tuples) {
				if (Arrays.equals(t1Tuple, t2Tuple)) {
					found = true;
					break;
				}
			}
			if (found)
				continue;
			else newTuples.add(t1Tuple);
		}
		return new Table(t1.cols, newTuples, t1.name + " - " + t2.name);		
	}
	
	/**
	 * Renames the first n columns with the names in the given string arraylist
	 * It will not fail if there are more columns than strings, but will if
	 * there are more strings than columns
	 * 
	 * FINISHED
	 */
	public static Table rename(Table t, ArrayList<String> newNames) {
		if (newNames.size() > t.cols.size()) {
			System.out.println("Too many arguments for number of columns, attributes not renamed\n");
			return t;
		}
		for (int i = 0; i < newNames.size(); i++) {
			t.cols.get(i).name = newNames.get(i);
		}
		t.name = "renamed " + t.name;
		return t;
	}
	
	/**
	 * Renames the first n columns with the names in the given string arraylist
	 * It will not fail if there are more columns than strings, but will if
	 * there are more strings than columns
	 * 
	 * FINISHED
	 */
	public static Table renameCopy(Table t1, ArrayList<String> newNames) {
		Table t = t1.getClone();
		if (newNames.size() > t.cols.size()) {
			System.out.println("Too many arguments for number of columns, attributes not renamed\n");
			return t;
		}
		for (int i = 0; i < newNames.size(); i++) {
			t.cols.get(i).name = newNames.get(i);
		}
		t.name = "renamed " + t.name;
		return t;
	}
	
	/**
	 * Returns the cartesian product of the two tables
	 * 
	 * FINISHED
	 */
	public static Table product(Table t1, Table t2) {
		ArrayList<TypedAttribute> allCols = new ArrayList<TypedAttribute>();
		
		for (TypedAttribute col : t1.cols)
			allCols.add(col);
		
		for (TypedAttribute col : t2.cols)
			allCols.add(col);
		
		ArrayList<TypedAttribute[]> allTuples = new ArrayList<TypedAttribute[]>();
		
		int numCols1 = t1.cols.size();
		int numCols2 = t2.cols.size();
		int totalCols = numCols1 + numCols2;
		
		//this goes through all the tupes in table 1
		for (TypedAttribute[] t1Tuple : t1.tuples) {
			//this goes through all the tuples in table 2
			for (TypedAttribute[] t2Tuple : t2.tuples) {
				//these are the values of both of the tuples commbined
				TypedAttribute[] comboTuple = new TypedAttribute[totalCols];
				int cnt = 0;
				//adds all the column vals for table 1s tuple
				for (int i = 0; i < numCols1; i++)
					comboTuple[cnt++] = t1Tuple[i];
				//adds all the column vals for table 2s tuple				
				for (int i = 0; i < numCols2; i++)
					comboTuple[cnt++] = t2Tuple[i];
				
				allTuples.add(comboTuple);
			}
		}
		
		return new Table(allCols, allTuples, t1.name + " * " + t2.name);
	}
	
	/**
	 * Inserts the given tuple into the table
	 * 
	 * FINISHED
	 */
	public static void insertTuple_1(Table t, TypedAttribute[] newTuple) {
		if (!t.checkForPKViolation(newTuple))
			t.addTuple(newTuple);
		else System.out.println("tuple could not be added because the PK already exists in table\n");
	}
	
	/**
	 * Deletes the tuples from the table that meet the condition
	 * 
	 * FINISHED
	 */
	public static Table deleteTuple(Table t, Condition c) {
		
		String colName = c.x.name;
		
		int numRows = t.numRows();
		
		//gets the column index of the column the condition is on
		int colIndex = t.getColIndex(colName);
		
		//this iterates through the table's tuples and checks to see if the
		//individual tuples satisfy the condition
		for (int i = numRows - 1; i >= 0; i--) {
			//this uses the values of the tuple's column that the condition
			//is being checked against to see if it meets the condition
			if (c.solve(t.tuples.get(i)[colIndex]))
				t.dropRow(i);
		}
		
		return t;
	}
	
	/**
	 * This function does a deletion with a comparison instead of a condition
	 * 
	 * FINISHED
	 */
	public static Table deleteTuple(Table t, Comparison c) {
				
		ArrayList<String> colNames = c.getColNames();
		
		int numRows = t.numRows();
		
		//gets the column index of the column the condition is on
		ArrayList<Integer> colIndexes = new ArrayList<Integer>();
		for (int i = 0; i < colNames.size(); i++)
			colIndexes.add(t.getColIndex(colNames.get(i)));
		
		//this iterates through the table's tuples and checks to see if the
		//individual tuples satisfy the condition
		for (int i = numRows - 1; i >= 0; i--) {
			//arrraylist that will hold all the values being checking in comparison
			ArrayList<TypedAttribute> tupleVals = new ArrayList<TypedAttribute>();
			
			//for each column that needs to be checked, the row values are extracted
			for (int j = 0; j < colIndexes.size(); j++)
				tupleVals.add(t.tuples.get(i)[colIndexes.get(j)]);
			
			//this uses the values of the tuple's column that the condition
			//is being checked against to see if it meets the condition
			if (c.solve(tupleVals))
				t.dropRow(i);
		}
		
		return t;
	}
	
	public static void deleteTable(Table t) {
		t = null; //whatever this does its supposed to delete this mf
	}

	public static void showTable(Table t) {
		String header = t.getHeaderString();
		String body = "";
		for (int i = 0; i < t.tuples.size(); i++) {
			body += t.getRowString(i) + "\n";
		}
		String sep = String.join("", Collections.nCopies(header.length()/2, "-"));
		System.out.println(sep);
		System.out.println(t.name);
		System.out.println(sep);
		System.out.print(header);
		System.out.println(sep);
		System.out.print(body);
		System.out.println(sep);
	}
	
	public static void printTuples(ArrayList<TypedAttribute[]> tups, String header) {
		String body = Table.tupleString(tups);
		System.out.print(header);
		System.out.println(body);
	}
	
}