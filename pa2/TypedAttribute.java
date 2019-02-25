import java.io.Serializable;


public class TypedAttribute implements Serializable {
	public String name;
	public Type val;
	public boolean isPK;
	
	TypedAttribute(String nname, Type type) {
		name = nname;
		val = type;
	}
	
	TypedAttribute(String nval) {
		name = nval;
		val = new VarcharT(nval);
	}
	
	TypedAttribute(int nval) {
		val = new IntegerT(nval);
		name = "" + nval;
	}
	
	public String toString() {
		return name;
	}
	
	public boolean isInteger() {
		return val.isInteger();
	}
	
	public boolean equals(TypedAttribute ta2) {
		if (this.name.equals(ta2.name) && this.val.typename.equals(ta2.val.typename))
			return true;
		else return false;
	}
}