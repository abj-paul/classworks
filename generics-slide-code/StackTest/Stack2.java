import java.util.NoSuchElementException;

public class Stack2 {
	
	// Passing generic Stack objects to generic methods.
	public static void main(String[] args) {
		Double[] doubleELements = {1.1, 2.2, 3.3, 4.4, 5.5};
		Integer[] integerElements = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		
		// Create a Stack<Double> and Stack<Integer>
		Stack<Double> doubleStack = new Stack<>(5);
		Stack<Integer> integerStack = new Stack<>();
		
		// push elements of doubleElements onto doubleStack
		testPush("doubleStack", doubleStack, doubleELements);
		testPop("doubleStack", doubleStack); // pop from doubleStack
		
		// push elements of integerElements onto integerStack
		testPush("integerStack", integerStack, integerElements);
		testPop("integerStack", integerStack); // pop from integerStack
	}	
	
	
	// generic method testPush pushes elements onto a Stack
	public static <E> void testPush(String name, Stack<E> stack, E[] elements) {
		System.out.printf("%nPushing elements onto %s%n", name);
		
		// push element onto Stack
		for(E element : elements) {
			System.out.printf("%s ", element);
			stack.push(element);
		}
	}
	
	// generic method testPop pops elements onto a Stack
	public static <E> void testPop(String name, Stack<E> stack) {
		// pop elements from stack
		try {
			System.out.printf("%nPopping elements from %s%n", name);
			E popValue; // store element removed from stack
			
			// remove all elements from Stack
			while(true) {
				popValue = stack.pop();
				System.out.printf("%s ", popValue);
			}
		}
		catch(NoSuchElementException noSuchElementException) {
			System.out.println();
			noSuchElementException.printStackTrace();
		}
	}
}
