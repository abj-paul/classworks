package producer.consumer;

public class UnsynchronizedBuffer implements Buffer {
	private int buffer=-1;

	@Override
	public void set(int value) {
		// TODO Auto-generated method stub
		System.out.printf("Write %d to buffer. ",value);
		this.buffer = value;
	}

	@Override
	public int get() {
		// TODO Auto-generated method stub
		System.out.printf("Read %d from buffer. ",this.buffer);
		return this.buffer;
	}

}
