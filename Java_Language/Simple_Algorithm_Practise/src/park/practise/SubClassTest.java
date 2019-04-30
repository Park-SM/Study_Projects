package park.practise;

//first  : Construct super-class's member field.
//second : Call super-class's constructor.
public class SubClassTest extends SuperClassTest {
	public String testString = "test!";
	
	public SubClassTest(int superParam) {
		super(superParam);	// super() Method is to call constructor of super-class.
							// super(superParam) -> SuperClassTest(int testInteger)
		System.out.println("This is constructor of SubClassTest\n");
	}
	
	public void TestingMethod_sub() {
		System.out.println("This is method of SubClassTest");
		System.out.println("testInteger: " + super.testInteger);
		// System.out.println("Test1: " + test1);   <- Error
		System.out.println("Test2: " + super.test2);
		System.out.println("Test3: " + super.test3);
		System.out.println();
		
	}
	
	public void setTest(String test2, String test3) {
		super.test2 = test2;
		super.test3 = test3;
		System.out.println("Updated test2 and test3!\n");
	}
}
