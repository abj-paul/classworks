import java.util.ArrayList;
import java.util.List;

// Totaling the numbers in a List<Number>
public class TotalNumbers {
	public static void main(String[] args) {
		// create, initialize and output List of Numbers containing both Integers and Doubles,
		// then display total of the elements
		Number[] numbers = {1, 2.4, 3, 4.1};  // Integers and Doubles
		List<Number> numberList = new ArrayList<>();
		
		for (Number element : numbers) {
			numberList.add(element); //place each number in numberList
		}
		
		System.out.printf("numberList contains: %s%n", numberList);
		System.out.printf("Total of the elements in numberList: %.1f%n", sum(numberList));
	}
	
	// calculate total of List elements
	public static double sum(List<Number> list) {
		double total = 0; // initialize total
		
		// calculate sum
		for (Number element : list) {
			total += element.doubleValue();
		}
		
		return total;
	}

}
