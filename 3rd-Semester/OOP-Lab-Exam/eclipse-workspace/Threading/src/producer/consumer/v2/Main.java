package producer.consumer.v2;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Buffer buffer = new UnsynchronizedBuffer();
		
		Thread producer_thread = new Thread(new Producer(buffer));
		Thread consumer_thread = new Thread(new Consumer(buffer));
		
		ExecutorService executorService = Executors.newCachedThreadPool();
		executorService.submit(consumer_thread);
		executorService.submit(producer_thread);
		
		executorService.shutdown();
	}

}
