import java.util.ArrayList;

public abstract class Subject {
	protected ArrayList<Observer> observers;
	protected SubjectState state;

	Subject(){
		this.observers = new ArrayList<>();
		this.state = new SubjectState("Initializer state");
	}

	public void attach(Observer observer){
		this.observers.add(observer);
	}
	public void detach(Observer observer){
		this.observers.remove(observer);
	}

	public abstract void setState(SubjectState state);
	public abstract SubjectState getState();

	public void notifyAllSubscriber(){
		for(Observer observer : observers) observer.update(this.state);
	}
}