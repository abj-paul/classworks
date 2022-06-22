package producer.consumer;

public interface Buffer {
	void set(int value) throws InterruptedException;
	int get() throws InterruptedException;
}
