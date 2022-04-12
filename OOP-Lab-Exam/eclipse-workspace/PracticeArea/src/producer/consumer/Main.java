package producer.consumer;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {

	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		Buffer buffer = new BlockingBuffer();

		ExecutorService executorService = Executors.newCachedThreadPool();
		executorService.execute(new Producer(buffer));
		executorService.execute(new Consumer(buffer));
		
		executorService.shutdown();
	}

}
