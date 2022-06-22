package producer.consumer;

import java.util.concurrent.ArrayBlockingQueue;

public class BlockingBuffer implements Buffer{
	private ArrayBlockingQueue<Integer> buffer;

	BlockingBuffer() throws InterruptedException{
		this.buffer = new ArrayBlockingQueue<Integer>(1);
		buffer.put(0);
	}
	@Override
	public void set(int value) throws InterruptedException {
		// TODO Auto-generated method stub
		buffer.put(value);
		System.out.printf("Write %d to buffer. ",value);
	}

	@Override
	public int get() throws InterruptedException {
		// TODO Auto-generated method stub
		int value = this.buffer.take();
		System.out.printf("Read %d from buffer. ",value);
		return value;
	}

}
