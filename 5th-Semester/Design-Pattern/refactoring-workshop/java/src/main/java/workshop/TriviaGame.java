package workshop;

import java.util.ArrayList;
import java.util.LinkedList;

public class TriviaGame {
    Question question;
    Player player;

    
    int currentPlayer = 0;
    boolean isGettingOutOfPenaltyBox;

    public TriviaGame() {
	question = new Question();
	player = new Player();
	question.createQuestion(Question.QUESTION_COUNT);
    }

    private void announceRoll(int playerIndex, int roll){
	Announcement.announce(player.players.get(playerIndex) + " is the current player");
	Announcement.announce("They have rolled a " + roll);
    }

    private boolean playerInPenaltyBox(int playerIndex){
	return player.inPenaltyBox[playerIndex];
    }
    private boolean oddRoll(int roll){
	return roll % 2 != 0;
    }

    private void getOutOfPenalty(){
	isGettingOutOfPenaltyBox = true;
	Announcement.announce(player.players.get(currentPlayer) + " is getting out of the penalty box");
    }
    
    private void getNewPlaceBasedOn(int roll){
        player.places[currentPlayer] = player.places[currentPlayer] + roll;
	if (player.places[currentPlayer] > 11) player.places[currentPlayer] = player.places[currentPlayer] - 12;
	
	Announcement.announce(player.players.get(currentPlayer)
		 + "'s new location is "
		 + player.places[currentPlayer]);
    }

    private void waitInPenaltyBox(){
	Announcement.announce(player.players.get(currentPlayer) + " is not getting out of the penalty box");
	isGettingOutOfPenaltyBox = false;
    }

    private void rejoinGame(int roll){
	getOutOfPenalty();
	getRoundQuestion(roll);
    }

    private void getRoundQuestion(int roll){
	getNewPlaceBasedOn(roll);
	
	Announcement.announce("The category is " + currentCategory());
	askQuestion();
    }


    public void roll(int roll) {
	announceRoll(currentPlayer, roll);
	
        if (playerInPenaltyBox(currentPlayer)){
            if (oddRoll(roll)) rejoinGame(roll);
            else waitInPenaltyBox();
        }
	else getRoundQuestion(roll);
    }

    private void askQuestion() {
        if (currentCategory() == "Pop")
	    Announcement.announce(question.popQuestions.removeFirst());
        if (currentCategory() == "Science")
	    Announcement.announce(question.scienceQuestions.removeFirst());
        if (currentCategory() == "Sports")
	    Announcement.announce(question.sportsQuestions.removeFirst());
        if (currentCategory() == "Rock")
	    Announcement.announce(question.rockQuestions.removeFirst());
    }


    private String currentCategory() {
        if (player.places[currentPlayer] == 0) return "Pop";
        if (player.places[currentPlayer] == 4) return "Pop";
        if (player.places[currentPlayer] == 8) return "Pop";
        if (player.places[currentPlayer] == 1) return "Science";
        if (player.places[currentPlayer] == 5) return "Science";
        if (player.places[currentPlayer] == 9) return "Science";
        if (player.places[currentPlayer] == 2) return "Sports";
        if (player.places[currentPlayer] == 6) return "Sports";
        if (player.places[currentPlayer] == 10) return "Sports";
        return "Rock";
    }

    private boolean correctAnswerEvent(){
	Announcement.announce("Answer was correct!!!!");
	player.purses[currentPlayer]++;
	Announcement.announce(player.players.get(currentPlayer)
		 + " now has "
		 + player.purses[currentPlayer]
		 + " Gold Coins.");

	gotoNextPlayer();
	return didPlayerWin();
    }

    private void gotoNextPlayer(){
	currentPlayer++;
	if (currentPlayer == player.players.size()) currentPlayer = 0;
    }

    public boolean wasCorrectlyAnswered() {
        if (playerInPenaltyBox(currentPlayer)) {
            if (isGettingOutOfPenaltyBox) return correctAnswerEvent();
            else {
		gotoNextPlayer();
                return true;
            }
        } else return correctAnswerEvent();
    }

    private void sendPlayerToPenaltyBox(int playerIndex){
        player.inPenaltyBox[playerIndex] = true;
    }

    private void announceWrongAnswer(){
	Announcement.announce("Question was incorrectly answered");
	Announcement.announce(player.players.get(currentPlayer) + " was sent to the penalty box");
    }

    public boolean wrongAnswer() {
	announceWrongAnswer();
	sendPlayerToPenaltyBox(currentPlayer);
	gotoNextPlayer();
        return true;
    }

    private boolean didPlayerWin() {
        return !(player.purses[currentPlayer] == 6);
    }

}

class Question{
    public static int QUESTION_COUNT = 50;

    public LinkedList<String> popQuestions = new LinkedList<String>();
    public LinkedList<String> scienceQuestions = new LinkedList<String>();
    public LinkedList<String> sportsQuestions = new LinkedList<String>();
    public LinkedList<String> rockQuestions = new LinkedList<String>();

    public void createQuestion(int questionCount){
	for (int i = 0; i < questionCount; i++) {
            popQuestions.addLast(createPopQuestion(i));
            scienceQuestions.addLast(createScienceQuestion(i));
            sportsQuestions.addLast(createSportsQuestion(i));
            rockQuestions.addLast(createRockQuestion(i));
        }
    }
    public String createPopQuestion(int index){
	return "Pop Question " + index;
    }
    public String createScienceQuestion(int index){
	return "Science Question " + index;
    }
    public String createSportsQuestion(int index){
	return "Sports Question " + index;
    }

    public String createRockQuestion(int index) {
        return "Rock Question " + index;
    }

    public boolean isPlayable(int totalPlayerCount) {
        return (totalPlayerCount >= 2);
    }
}

class Player {
    ArrayList<String> players = new ArrayList<String>();
    int[] places = new int[6];
    int[] purses = new int[6];
    boolean[] inPenaltyBox = new boolean[6];

    public boolean add(String playerName) {
	initializeNewPlayerInfo(playerName);
	announcePlayerAddition(playerName);
        return true;
    }

    private void initializeNewPlayerInfo(String playerName){
	players.add(playerName);
        places[howManyPlayers()] = 0;
        purses[howManyPlayers()] = 0;
        inPenaltyBox[howManyPlayers()] = false;
    }

    private void announcePlayerAddition(String playerName){
	Announcement.announce(playerName + " was added");
        Announcement.announce("They are player number " + players.size());
    }

    public int howManyPlayers() {
        return players.size();
    }   
}

class Announcement {
    public static void announce(Object message) {
        System.out.println(message);
    }
}
