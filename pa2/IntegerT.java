//import Type.java;

//package Type;

public class IntegerT extends Type {
	Integer val;
	public String typename;
	
	IntegerT(int i) {
		this.val = i;
		typename = "INTEGER";
	}
	
	IntegerT() {
		this.val = 0;
		typename = "INTEGER";
	}
	
	public String toString() {
		return typename;
	}
	
	public String toStringVal() {
		return val + "";
	}
	
	public boolean isInteger() {
		return true;
	}
}