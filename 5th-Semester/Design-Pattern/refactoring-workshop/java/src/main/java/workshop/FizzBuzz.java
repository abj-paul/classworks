package workshop;

/**
 * Requirements:
 * For factor of three print Fizz instead of the number
 * For factor of five print Buzz instead of the number
 * For numbers which are factors of both three and five print FizzBuzz instead of the number
 */

public class FizzBuzz {
    public static String say(int number){
	if(divisibleByFiveOrThree(number)) return sayTheWordFor(number);
	else return sayNumber(number);
    } 

    private static boolean divisibleByFiveOrThree(int number){
	return (number % 5==0) || (number % 3==0);
    }
    private static String sayTheWordFor(int number){
        if (number % 15 == 0) return "FizzBuzz";
	if (number % 3 == 0) return "Fizz";
	if (number % 5 == 0) return "Buzz";
	return "Error";
    }
    private static String sayNumber(int number){
	return String.valueOf(number);
    }
}

