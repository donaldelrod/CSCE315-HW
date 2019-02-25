//package Type;
import java.io.Serializable;


public class Type implements Serializable {
	public String typename = "Type";
	public Type val;
	
	public String toString() {
		return typename;
	}
	
	public String toStringVal() {
		return val + "";
	}
	
	public boolean isInteger() {
		return val.isInteger();
	}
}