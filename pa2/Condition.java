import java.util.*;
//import Type.*;
//import IntegerT.java;
//import VarcharT.java;


//so maybe make a superclass for compound conditions, and then solve them seperatly there or solve this if it is not compound, will look into this


public class Condition { //extends Comparison {
	public TypedAttribute x;
	public TypedAttribute y;
	public String op;
	public Condition and;
	
	
	String operations[] = {"==", "<=", ">=", "!=", "<", ">", "&&", "||"};
	
	//after the object is created, the result of the condition can be found by accessing the member "ret"
	public Condition (TypedAttribute a, TypedAttribute b, String nop) {//, Condition newC = null) {
		this.x = a;
		this.y = b;
		this.op = nop;
		//this.and = newC;
	}
	
	public boolean solve(TypedAttribute newX) {
		
		if (this.isCompound()) {
			//when calling solve, check if the condition is compound. if not, then it should try to resolve the compound condition
			//first, and should be done so recursively. additional logic will need to be added to the functions that call the solve 
			//function, but will easy the burden of this function and the logic of the condition class
		}
		
		if (newX.val instanceof VarcharT && this.y.val instanceof VarcharT) {
						
			String xs = ((VarcharT)newX.val).val;
			String ys = ((VarcharT)y.val).val;
			
			if (this.op.equals("==")) 
				return xs.equals(ys);
			else if (this.op.equals("!="))
				return !xs.equals(ys);
			else return false;
		}
		else if (newX.val instanceof IntegerT && this.y.val instanceof IntegerT) {
						
			int xi = ((IntegerT)newX.val).val;
			int yi = ((IntegerT)y.val).val;
			
			switch (this.op) {
			case ">":
				return xi > yi;
			case "<":
				return xi < yi;
			case ">=":
				return xi >= yi;
			case "<=":
				return xi <= yi;
			case "==":
				return xi == yi;
			case "!=":
				return xi != yi;
			default:
				return false;
			}
		}
		else return false; //we need to throw some sort of error here if the types mismatch or if an op is called on unsupported types
	}
	
	public boolean isCompound() {
		return and == null;
	}
}
