package producer.consumer.v2;

public class UnsynchronizedBuffer implements Buffer {
	private int buffer = -1;
	@Override
	public void set(int value) {
		// TODO Auto-generated method stub
		buffer = value;
		System.out.printf("Producer writes %d",value);
		
	}

	@Override
	public int get() {
		// TODO Auto-generated method stub
		System.out.printf("Consumer reads %d",buffer);
		return buffer;
	}

}
