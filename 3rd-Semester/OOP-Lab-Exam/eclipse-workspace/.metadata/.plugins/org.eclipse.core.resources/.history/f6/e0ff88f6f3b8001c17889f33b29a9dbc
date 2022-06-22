package sleep.join.thread;

public class Main {
	public static void main(String[] args) {
		System.out.println("Application starts.");
		Printer printer = new Printer(1);
		Tasks task = new Tasks(printer);
		Thread t1 = new Thread(task);
		
		Thread t2 = new Thread(new Tasks(printer));
		t1.start();
		try {
			t1.join();
		}catch(InterruptedException e) {e.printStackTrace();}
		t2.start();
		System.out.println("Application ends.");

	}
}
