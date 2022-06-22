package stack_example;

public class EmptyStackException extends RuntimeException{
	EmptyStackException(){
		this("Stack is empty! Can not pop anymore.");
	}
	EmptyStackException(String message){
		super(message);
	}
}
