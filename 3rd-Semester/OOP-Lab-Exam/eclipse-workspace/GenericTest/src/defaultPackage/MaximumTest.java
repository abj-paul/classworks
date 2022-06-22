package defaultPackage;

public class MaximumTest {
	public static <T extends Comparable<T>> T maximum(T a, T b, T c) {
		T max = a;
		if(max.compareTo(b)<0) max = b;
		if(max.compareTo(c)<0) max = c;
		return max;
	}
	public static void main(String[] args) {
	    System.out.printf("Max of %d, %d and %d is %d\n\n", 3, 4, 5, maximum( 3, 4, 5 ));

	    System.out.printf("Max of %.1f,%.1f and %.1f is %.1f\n\n",
	    	         6.6, 8.8, 7.7, maximum( 6.6, 8.8, 7.7 ));

	    System.out.printf("Max of %s, %s and %s is %s\n","pear",
	    	         "apple", "orange", maximum("pear", "apple", "orange"));
	}
}
