package producer.consumer.v2;
import java.util.Random;

public class Producer implements Runnable{
	private final static Random randomGenerator = new Random();
	private Buffer sharedBuffer;
	
	Producer(Buffer sharedBuffer){
		this.sharedBuffer=sharedBuffer;
	}
	
	public void run() {
		try {
			int sum=0;
			for(int count=0; count<=10; count++) {
				sharedBuffer.set(count);
				sum+=count;
				System.out.printf(" and sum=%d\n",sum);
				Thread.sleep(this.randomGenerator.nextInt(500));
			}
		}catch(InterruptedException e) {e.printStackTrace();}
		System.out.println("Producer has completed its work.");
	}
}
