package Basic;

public class Belief {
	private int age;
	private String country;
	
	public Belief(int age, String country){
		this.age = age;
		this.country = country;
	}
	
	Belief(String country){
		this.age = 18;
		this.country = country;
	}
	public Belief(){}
	
	private int showCastle() {
		System.out.println("I am showing the castle around!");
		return 1;
	}
}
