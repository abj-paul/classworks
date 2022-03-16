

public class StackTest{
	private double[] doubleElements = {1.1,2.2,3.3};
	private int[] integerElements = {1,2,3,4,5,6,7,8,9};

	private Stack<Double> doubleStack;
	private Stack<Integer> integerStack;

	public void testStacks(){
		doubleStack = new Stack<Double>(5);
		integerStack = new Stack<Integer>(10);

		testPushDouble();
		testPopDouble();
		testPushInteger();
		testPopInteger();
	}

	public void testPushDouble(){
		try{
			System.out.println("\nPusing elements onto doubleStack");

			for(double element: doubleElements){
				System.out.println("%.1f ",element);
				doubleStack.push(element);
			}
			
		}catch(FullStackException fullStackException) {
			System.out.println();
			fullStackException.printStackTrace();
		}
	}

	public void testPopDouble(){
		try{
			System.out.println("\nPopping element from doubleStack");
			double popValue;

			while(true){
				popValue = doubleStack.pop();
				System.out.printf("%.1f",popValue);
			}
		}catch( EmptyStackException emptyStackException){
			Syste.err.println();
			emptyStackException.printStackTrace();
		}
	}	

	public void testPushInteger(){
		try{
			System.out.println("\nPusing elements onto integerStack");

			for(double element: integerStack){
				System.out.println("%d ",element);
				integerStack.push(element);
			}
			
		}catch(FullStackException fullStackException) {
			System.out.println();
			fullStackException.printStackTrace();
		}
	}

	public void testPopInteger(){
		try{
			System.out.println("\nPopping element from integerStack");
			double popValue;

			while(true){
				popValue = integerStack.pop();
				System.out.printf("%d",popValue);
			}
		}catch( EmptyStackException emptyStackException){
			Syste.err.println();
			emptyStackException.printStackTrace();
		}
	}	

	public static void main(String[] args){
		StackTest application = new StackTest();
		application.testStacks();
	}
}
