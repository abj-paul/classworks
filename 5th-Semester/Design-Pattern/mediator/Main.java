import java.util.ArrayList;
import java.util.List;

interface ChatMediator {
    public void addUser(User user);
    void sendMessage(String message, User fromUser, User toUser);
}

class ChatMediatorImpl implements ChatMediator {
    private List<User> users;

    public ChatMediatorImpl() {
        users = new ArrayList<>();
    }

    public void addUser(User user) {
        users.add(user);
    }

    @Override
    public void sendMessage(String message, User fromUser, User toUser) {
        toUser.receiveMessage(message, fromUser);
    }

    public void sendMessage(String message, User fromUser, String state) {
        if(state.toUpperCase().equals("ALL")) {
            for(User user : users) {
                if(!user.equals(fromUser)) user.receiveMessage(message, fromUser);
            }
        }
        else if(state.toUpperCase().equals("TWO")){
            users.get(0).receiveMessage(message, fromUser);
            users.get(1).receiveMessage(message, fromUser);
        }
    }
}

class User {
    private String name;
    private ChatMediator mediator;

    public User(String name, ChatMediator mediator) {
        this.name = name;
        this.mediator = mediator;
    }

    public void sendMessage(String message, User toUser) {
        mediator.sendMessage(message, this, toUser);
    }

    public void receiveMessage(String message, User fromUser) {
        System.out.println(this.name + " received a message from " + fromUser.getName() + ": " + message);
    }

    public String getName() {
        return name;
    }
}

public class Main {
    public static void main(String[] args) {
        ChatMediator mediator = new ChatMediatorImpl();

        User alice = new User("Alice", mediator);
        User bob = new User("Bob", mediator);
        User charlie = new User("Charlie", mediator);

        mediator.addUser(alice);
        mediator.addUser(bob);
        mediator.addUser(charlie);

        alice.sendMessage("Hello Bob!", bob);
        bob.sendMessage("Hi Charlie!", charlie);
    }
}
