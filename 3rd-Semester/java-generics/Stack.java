
public class Stack<E>{
	private final int size;
	private int top;
	private E[] elements;

	public Stack() {
		this(10);
	}
	public Stack(int s){
		size = s>0 ? s : 10;
		top=-1;

		this.elements = (E[]) new Object[size];
	}

	public void push(E pushValue){
		if(top==size-1){
			throw new FullStackException(String.format("Stack is full, cannot push %s",pushValue));
		}
		elements[++top] = pushValue;
	}

	public E pop(){
		if(top==-1){
			throw new EmptyStackException("Stack is empty, cannot pop");
			return elements[top--];
		}
	}
}

public class FullStackException extends RuntimeException {
	public FullStackException(){
		this("Stack is full.");
	}

	public FullStackException(String exception){
		super(exception);
	}
}
