import Type.java;
import java.lang.*;

public class VARCHAR implements Type {
	String s;
	int maxLen;
	
	public void VARCHAR(String ns, int max) {
		maxLen = max;
		if (ns.length() > maxLen)
			ns = ns.substring(0, maxLen);
		s = ns;
	}
}