package patterns;

import java.util.ArrayList;

public class Authentication {
    private ArrayList<User> registeredUsers, loggedInUsers;
    private static Authentication authentication = null;

    private Authentication(){
        this.registeredUsers = new ArrayList<>();
        this.loggedInUsers = new ArrayList<>();
    }

    public static Authentication getAuthenticationInstance(){
        if(authentication==null) authentication = new Authentication();
        return authentication;
    }

    public User registerAccount(String username, String password, String email, String address, String role){
        User user = null;
        if(role.toUpperCase().equals("SELLER")){
            user = new Seller(username, email, password, address);
        }else user = new Buyer(username, email, password, address);

        registeredUsers.add(user);
        return user;
    }

    public User login(String username, String password){
        for(User user : registeredUsers){
            if(user.getUserName().equals(username) && user.getPassword().equals(password)){
                this.loggedInUsers.add(user);
                return user;
            }
        }
        return null;
    }

    public boolean authenticate(User givenUser){
        for(User user: loggedInUsers){
            if(user.equals(givenUser)) return true;
        }
        return false;
    }

    public void logout(User user){
        this.loggedInUsers.remove(user);
    }

    public void notifyAllUsers(String msg){
        for(User user: loggedInUsers) user.addNotification(msg);
    }
    
}
