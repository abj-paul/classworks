package sort.customClass;

public class Sort<T extends Comparable>{
	T[] storage;
	
	Sort(T[] initializer){
		this.storage = (T[])new Comparable[initializer.length];
		for(int i=0; i<initializer.length; i++) this.storage[i]=initializer[i];
	}
	
	void sort() {
		for(int i=0; i<this.storage.length-1; i++) {
			for(int j=1+1; j<this.storage.length; j++) {
				if(this.storage[i].compareTo(this.storage[j])>0) {
					//Swap
					T temp = this.storage[i];
					this.storage[i] = this.storage[j];
					this.storage[j] = temp;
				}
			}
		}
	}
	
	void print() {
		for(int i=0; i<this.storage.length; i++) {
			System.out.println(this.storage[i].toString());
		}
	}
}
