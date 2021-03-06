package basic.threading;

public class Main {
	public static void main(String[] args) {
		System.out.println("Application starts.");
		Printer printer = new Printer(1);
		Tasks task = new Tasks(printer);
		Thread t1 = new Thread(task);
		t1.start();
		
		Printer printer2 = new Printer(2);
		Thread t2 = new Thread(new Tasks(printer2));
		t2.start();
		System.out.println("Application ends.");
	}
}
