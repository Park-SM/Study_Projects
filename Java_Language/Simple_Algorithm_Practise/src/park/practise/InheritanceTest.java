package park.practise;

public class InheritanceTest {
	public static void main(String[] args) {
		SubClassTest subObject = new SubClassTest(10);
		subObject.TestingMethod_super();
		subObject.TestingMethod_sub();
		
		subObject.setTest("Park", "SangMin");
		subObject.TestingMethod_sub();
		subObject.PrintTest_super();
	}
}
