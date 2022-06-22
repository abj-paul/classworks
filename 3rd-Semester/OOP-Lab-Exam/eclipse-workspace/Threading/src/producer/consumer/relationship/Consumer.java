package producer.consumer.relationship;

public class Consumer implements Runnable{
	Storage storageRef;
	final int max = 500;
	final int min = 300;
	Consumer(Storage storageRef){
		this.storageRef = storageRef;
	}
	
	public void run() {
		for(int i=0; i<storageRef.get_size()-5; i++) {
			this.storageRef.read();
			try {
			long delay = (long)Math.random()*(max-min+1)+min;   
			Thread.sleep(delay);
			}catch(InterruptedException e) {e.printStackTrace();}
		}
	}
}
