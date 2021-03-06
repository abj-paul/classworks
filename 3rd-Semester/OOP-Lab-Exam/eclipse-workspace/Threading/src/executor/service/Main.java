package executor.service;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {
	public static void main(String[] args) {
		System.out.println("Application starts.");
		
		ExecutorService threadExecutor = Executors.newFixedThreadPool(2); 
		
		for(int i=1; i<=4; i++) {
			Thread thread = new Thread(new Tasks(new Printer(i)));
			threadExecutor.execute(thread);
		}
		
		threadExecutor.shutdown();
		
		
		System.out.println("Application ends.");
	}
}
