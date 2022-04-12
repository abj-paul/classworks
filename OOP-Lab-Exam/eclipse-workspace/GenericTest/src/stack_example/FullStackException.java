package stack_example;

public class FullStackException extends RuntimeException{
	FullStackException(){
		this("Stack is full! Can no longer push.");
	}
	FullStackException(String message){
		super(message);
	}
}
