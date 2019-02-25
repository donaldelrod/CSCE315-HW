import java.util.*;

public class Comparison {
	public Condition a;
	public Condition b;

	public String op;
	
		
	public Comparison(Condition x, Condition y, String nop) {
		this.a = x;
		this.b = y;
		this.op = nop;
	}
	
	public boolean solve(ArrayList<TypedAttribute> tupleVals) {
		
		if (op.equals("&&")) {
			if (a.solve(tupleVals.get(0)) && b.solve(tupleVals.get(1)))
				return true;
		}
		else if (op.equals("||")) {
			if (a.solve(tupleVals.get(0)) || b.solve(tupleVals.get(1)))
				return true;
		}
		return false;
	}
	
	public ArrayList<String> getColNames() {
		ArrayList<String> colNames = new ArrayList<String>();
		
		colNames.add(a.x.name);
		colNames.add(b.x.name);
		
		return colNames;
	}
}