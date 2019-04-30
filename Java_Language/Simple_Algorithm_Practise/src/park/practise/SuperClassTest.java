package park.practise;

public class SuperClassTest {
	private String test1 = "private: Cannot inherit";
	public String test2 = "public: Can inherit";
	protected String test3 = "protected: Can inherit";
	public int testInteger;
	
	public SuperClassTest(int testInteger) {
		this.testInteger = testInteger;
		System.out.println("This is constructor of SuperClassTest");
	}
	
	public void TestingMethod_super() {
		System.out.println("This is method of SuperClassTest\n");
	}
	
	public void PrintTest_super() {
		System.out.println("PrintTest2_super: " + test2);
		System.out.println("PrintTest3_super: " + test3);
	}
}
