package sort.customClass;

public class Player implements Comparable{
	String Name;
	public int age;
	
	Player(String name, int age){
		this.Name = name;
		this.age = age;
	}
	
	
	@Override
	public String toString() {
		String line = "("+this.Name+","+this.age+")";
		return line;
		
	}

	@Override
	public int compareTo(Object p) {
		return this.age - ((Player)p).age;
	}
}
