package synchronization;

public class Main {
	public static void main(String[] args) {
		System.out.println("Application starts.");
		Printer printer = new Printer(1);
		Tasks task = new Tasks(printer);
		Thread t1 = new Thread(task);
		
		Thread t2 = new Thread(new Tasks(printer));
		t1.start();
		t2.start();
		System.out.println("Application ends.");
	}
}

/*
 * package synchronization;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {
	public static void main(String[] args) {
		System.out.println("Application starts.");
		
		ExecutorService threadExecutor = Executors.newFixedThreadPool(10); 
		
		for(int i=1; i<=100; i++) {
			Thread thread = new Thread(new Tasks(new Printer(i)));
			threadExecutor.execute(thread);
		}
		
		threadExecutor.shutdown();
		
		
		System.out.println("Application ends.");
	}
}

 */