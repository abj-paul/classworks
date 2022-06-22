package producer.consumer;

import java.util.Random;

public class Consumer implements Runnable{
	private Buffer buffer;
	private final Random randomGenerator = new Random();
	
	Consumer(Buffer buffer){
		this.buffer = buffer;
	}
	
	@Override
	public void run() {
		try {
			//Thread.sleep(randomGenerator.nextInt(600));

			int sum=0;
		for(int count=1; count<=10; count++) {
			Thread.sleep(700);
			int value = this.buffer.get();
			sum+=value;
			System.out.printf(" Sum=%d\n",sum);
		}
		}catch(InterruptedException e) {e.printStackTrace();}
	}
	
}
