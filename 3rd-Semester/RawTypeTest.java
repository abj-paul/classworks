public class RawTypeTest{
	private Double[] doubleElements = {1.1,2.2,3.3,4.4,5.5};
	private Integer[] integerElements = {1,2,3,4,5,6,7,8};

	public void testStacks(){
		Stack rawTypeStack1 = new Stack(5);
		Stack rawTypeStack2 = new Stack<Double>(5);
		Stack<Integer> integerStack = new Stack(10);

		testPush("rawTypeStack1", rawTypeStack1, doubleElements);
		testPop("rawTypeStack1", rawTypeStack1);
		testPush("rawTypeStack2", rawTypeStack2, doubleElements);
		testPop("rawTypeStack2", rawTypeStack2);
		testPush
	}
}
