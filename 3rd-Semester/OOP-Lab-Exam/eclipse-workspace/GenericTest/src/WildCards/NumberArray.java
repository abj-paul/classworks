package WildCards;

import java.util.ArrayList;

public class NumberArray {
	public static void main(String[] args) {
		
	}
	
	void test_cases() {
		Integer[] integerArr = {2,3,4,5,6};
		ArrayList<Integer> integerArrayList = new ArrayList<Integer>();
		for(Integer element: integerArr) integerArrayList.add(element);
		print(integerArrayList);
		
		Double[] doubleArr = {2.2,3.0,42.1,5.0,6.1};
		ArrayList<Double> doubleArrayList = new ArrayList<Double>();
		for(Double element: doubleArr) doubleArrayList.add(element);
		print(doubleArrayList);
		
		Number[] numberArr = {2,3,4,5,6};
		ArrayList<Number> numberArrayList = new ArrayList<Number>();
		for(Number element: numberArr) numberArrayList.add(element);
		print(numberArrayList);
	
	}
	
	static void print(ArrayList<? extends Number> arrayList) {
		for(Number number: arrayList) {
			System.out.println(number.doubleValue()+" ");
		}
	}
}
