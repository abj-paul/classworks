package defaultPackage;

public class GenericArray {
	public static <T> void printArray(T[] arr) {
		for(int i=0; i<arr.length; i++) System.out.println(arr[i]);
	}
	public static void main(String[] args) {
		Integer[] arr = {1,3,4,5,5};
		GenericArray.printArray(arr);
	}
}
