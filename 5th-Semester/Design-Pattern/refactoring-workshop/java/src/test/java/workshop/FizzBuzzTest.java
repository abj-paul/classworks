package workshop;

import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static workshop.FizzBuzz.say;

public class FizzBuzzTest {
    @Test
    public void returnsANumber() {
        assertEquals("1", say(1));
        assertEquals("4", say(4));
        assertEquals("7", say(7));
    }

    @Test
    public void factorOf3() {
        assertEquals("Fizz", say(3));
        assertEquals("Fizz", say(6));
        assertEquals("Fizz", say(9));
    }

    @Test
    public void factorOf5() {
        assertEquals("Buzz", say(5));
        assertEquals("Buzz", say(10));
        assertEquals("Buzz", say(20));
    }

    @Test
    public void factorOf3And5() {
        assertEquals("FizzBuzz", say(15));
        assertEquals("FizzBuzz", say(30));
        assertEquals("FizzBuzz", say(60));
    }
}