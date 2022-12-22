package workshop;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.assertEquals;

public class TriviaGameTest {
    FakeTriviaGame game = new FakeTriviaGame();

    @Test
    public void correctlyAnswered() {
        game.add("Chet");
        game.add("Pat");
        game.roll(2);
        game.wasCorrectlyAnswered();

        assertEquals(Arrays.asList(
                "Chet was added",
                "They are player number 1",
                "Pat was added",
                "They are player number 2",
                "Chet is the current player",
                "They have rolled a 2",
                "Chet's new location is 2",
                "The category is Sports",
                "Sports Question 0",
                "Answer was correct!!!!",
                "Chet now has 1 Gold Coins."), game.getMessages());
    }

    @Test
    public void wronglyAnswered() {
        game.add("Chet");
        game.add("Pat");
        game.roll(1);
        game.wrongAnswer();

        assertEquals(Arrays.asList(
                "Chet was added",
                "They are player number 1",
                "Pat was added",
                "They are player number 2",
                "Chet is the current player",
                "They have rolled a 1",
                "Chet's new location is 1",
                "The category is Science",
                "Science Question 0",
                "Question was incorrectly answered",
                "Chet was sent to the penalty box"), game.getMessages());
    }

    class FakeTriviaGame extends TriviaGame {
        List<String> messages = new ArrayList<>();

        @Override
        protected void announce(Object message) {
            messages.add(String.valueOf(message));
        }

        protected List<String> getMessages() {
            return messages;
        }
    }
}
