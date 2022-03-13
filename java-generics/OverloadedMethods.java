
public class OverloadedMethods {
	public static void printArray(Integer[] inputArray){
		for(Integer element: inputArray)
			System.out.println("%s ",element);

		System.out.println();
	}

	public static void printArray(Double[] inputArray){
		for(Double element: inputArray)
			System.out.println("%s ",element);
		System.out.println();
	}

	public static void printArray(Character[] inputArray){
		for(Character element: inputArray)
			System.out.println("%s ",element);
		System.out.println();

	}

	public static void main(String args[]){
		Integer[] integerArray = {1,2,3,4,5,6};
		Double[] doubleArray = {1.1,2.2,3.3,4.4,5.5,6.6,7.8};
		Character[] characterArray = {'H','E','L','L','O'};

		System.out.println("Array integerArray contains: ");
		printArray(integerArray);
		System.out.println("Array doubleArray contains: ");
		printArray(doubleArray);
		System.out.println("Array characterArray contains: ");
		printArray(characterArray);


	}
}
