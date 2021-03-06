package producer.consumer.v2;

import java.util.Random;

public class Consumer implements Runnable{
	private final static Random randomGenerator = new Random();
	private Buffer sharedBuffer;
	
	Consumer(Buffer sharedBuffer){
		this.sharedBuffer=sharedBuffer;
	}
	
	public void run() {
		try {
			int sum=0;
			for(int i=0; i<=10; i++) {
				sum+=sharedBuffer.get();
				System.out.printf(" and sum=%d\n",sum);
				Thread.sleep(this.randomGenerator.nextInt(500));
			}
		}catch(InterruptedException e) {e.printStackTrace();}
		System.out.println("Consumer has completed its work.");
	}
}
