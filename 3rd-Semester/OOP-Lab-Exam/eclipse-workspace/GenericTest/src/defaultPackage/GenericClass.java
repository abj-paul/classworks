package defaultPackage;

public class GenericClass<T>{
	T[] arr;
	GenericClass(T[] arr){
		this.arr = arr;
	}
	void print() {
		GenericArray.printArray(this.arr);
	}
	
	public static void main(String[] args) {
		Double[] arr = {1.1,2.2,3.3};
		GenericClass<Double>g = new GenericClass<Double>(arr);
		g.print();
	}
}
