package park.practise;

// Default Package, Compiler does auto importing.
//import java.lang.*;

public class StringTest {
	public static void main(String[] args) {
		String str1 = new String("Park");
		String str2 = new String("Park");
		
		System.out.println(str1);
		System.out.println(str1.hashCode());	// Be Inherited from Object class.
		
		System.out.println(str2);
		System.out.println(str2.hashCode());
		
		if (str1 == str2) System.out.println("같다.");	// Compare address of str1-object and address of str2-object.
		else System.out.println("다르다.");
		
		if(str1.equals(str2)) System.out.println("같다.");	// Compare string of str1-object and string of str2-object.
		else System.out.println("다르다.");
	}
}
