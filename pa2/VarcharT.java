//import Type.java;
import java.lang.*;

//package Type;

public class VarcharT extends Type {
	public String val;
	public int maxLen;
	public String typename;
	
	VarcharT(String ns, int max) {
		maxLen = max;
		if (ns.length() > maxLen)
			ns = ns.substring(0, maxLen);
		val = ns;
		typename = "VARCHAR(" + maxLen + ")";
	}
	
	VarcharT(int nmaxLen) {
		val = "";
		maxLen = nmaxLen;
		typename = "VARCHAR(" + maxLen + ")";
	}
	
	VarcharT(String ns) {
		val = ns;
		typename = "VARCHAR";
	}
	
	public String toString() {
		return typename;
	}
	
	public String toStringVal() {
		return val;
	}
	
	public boolean isInteger() {
		return false;
	}
}