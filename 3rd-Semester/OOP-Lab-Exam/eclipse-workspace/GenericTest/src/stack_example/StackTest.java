package stack_example;

public class StackTest {
	public static void main(String[] args) {
		Stack<Integer> stack = new Stack<Integer>();
		Integer[] arr = {1,2,3,4,5};
		
		StackTest test = new StackTest();
		test_push(arr, stack);
		test.test_pop(stack);
	}
	
	public static <T> void test_push(T[] arr, Stack<T> stack){
		try {
		for(T element: arr) {
			System.out.printf("Pushing %s to stack.\n",element);
			stack.push(element);
		}
		}catch(FullStackException e) {e.printStackTrace();}
	}
	<T> void test_pop(Stack<T>stack) {
		try {
		while(true) {
			T element = stack.pop();
			System.out.printf("Popped %s from stack.\n",element);
		}
		}catch(EmptyStackException e) {e.printStackTrace();}
	}
}
