import java.util.ArrayList;
import java.util.NoSuchElementException;

// Stack generic class declaration.
public class Stack<E> {
	private final ArrayList<E> elements; // ArrayList stores stack elements
	
	// no-argument constructor creates a stack of the default size
	public Stack() {
		this(10); // default stack size
	}
	
	// Constructor creates a stack of the specified number of elements
	public Stack(int capacity) {
		int initCaoacity = capacity > 0 ? capacity : 10; // validate
		elements = new ArrayList(initCaoacity); // create ArrayList
	}
	
	// push element onto stack
	public void push(E pushValue) {
		elements.add(pushValue); // place pushValue on Stack
	}
	
	// return the top element if not empty; else throw exception
	public E pop() {
		if(elements.isEmpty()) { // if stack is empty
			throw new NoSuchElementException("Stack is empty, cannot pop");
		}
		
		// remove and return top element of Stack
		return elements.remove(elements.size() - 1);
	}
}
