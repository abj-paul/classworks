
import java.util.ArrayList;
import java.util.List;

public class WildcardTest {
	public static void main(String[] args) {
		// Create, initialize and output List of Integers, then display total of the elements
		Integer[] integers = {1, 2, 3, 4, 5};
		List<Integer> integerList = new ArrayList<>();
		
		// insert elements in integerList
		for(Integer element : integers) {
			integerList.add(element);
		}
		
		System.out.printf("integerList contains: %s%n", integerList);
		System.out.printf("Total of the elements in integerList: %.0f%n%n", sum(integerList));
		
		// Create, initialize and output List of Doubles, then display total of the elements
		Double[] doubles = {1.1, 3.3, 5.5};
		List<Double> doubleList = new ArrayList<>();
		
		// insert elements in integerList
		for(Double element : doubles) {
			doubleList.add(element);
		}
		
		System.out.printf("integerList contains: %s%n", doubleList);
		System.out.printf("Total of the elements in doubleList: %.1f%n%n", sum(doubleList));
		
		// Create, initialize and output List of Doubles, then display total of the elements
		Number[] numbers = {1.1, 3.3, 5.5};
		List<Number> numbersList = new ArrayList<>();
		
		// insert elements in integerList
		for(Number element : numbers) {
			numbersList.add(element);
		}
		
		System.out.printf("numberList contains: %s%n", numbersList);
		System.out.printf("Total of the elements in numbersList: %.1f%n%n", sum(numbersList));
	}
	
	// total the elements; using a wildcard in the List parameter
	public static double sum(List<? extends Number> list) {
		double total = 0; // initialize total
		
		// calculate sum
		for(Number element : list) {
			total += element.doubleValue();
		}
		
		return total;
	}

}
