package producer.consumer.relationship;

public class Main {
	public static void main(String[] args) {
		Integer[] initializer = {31,65,32,43,21};
		Storage storage = new Storage(initializer);
		
		Producer producer = new Producer(storage);
		Consumer consumer = new Consumer(storage);
		
		Thread t1 = new Thread(producer);
		Thread t2 = new Thread(consumer);
		
		t1.start();
		t2.start();
	}
}
