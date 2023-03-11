import java.io.*;
import java.util.*;

class Product {
    private String name, description, owner;
    private Integer inventory;
    private Double price;
    private Image image;

    Product(String name, String description, Double price, Integer inventory, Image image, String owner ){
	this.name = name;
	this.description = description;
	this.price = price;
	this.inventory = inventory;
	this.image = image;
	this.owner = owner;
    }

    public String getOwner(){
	return this.owner;
    }

    @Override
    public String toString(){
	return "----"+this.name+"----\n"+ this.description + "\nPrice" + String.valueOf(price) +"\nInventory: "+ String.valueOf(inventory) + "\n Image: "+image+"\n";
    }
}

class Image {
    private String fileLocation;
    private String fileMetaData;

    Image(String fileLocation, String fileMetaData){
	this.fileLocation = fileLocation;
	this.fileMetaData = fileMetaData;
    }
}

class User {
    private String username, email, password, address;

    User(String username, String email, String password, String address){
	this.username = username;
	this.email = email;
	this.password = password;
	this.address = address;
    }

    public String getUserName(){
	return this.username;
    }

    public String getPassword(){
	return this.password;
    }

}

class Payment {
    private String credit_card, PayPal, cryptocurrency;


    String generatePaymentReceipt(){
	return "Date + Payment Amount + Payment Method + Product List";
    }

    String notifyOrderConfirmation(){
	return "User's order for Product has been confirmed.";
    }
}


public class Main {
    static ArrayList<User> users = new ArrayList<User>();
    static ArrayList<Product> products = new ArrayList<Product>();
    static User currSessionUser = null;
    static Scanner kbd = new Scanner(System.in);

    public static void main(String[] args){
	
		while(true){
		try{
			String userInput;
			System.out.println("#####Welcome to E-Commerce System#####");
		
			if(currSessionUser == null){
				System.out.println("Login/Signup:");
				userInput = kbd.nextLine();
				if(userInput.toUpperCase().equals(Constant.SIGNUP)) signup();
				else if(userInput.toUpperCase().equals(Constant.LOGIN)) login();
			}
			else if(currSessionUser!=null){
				System.out.println("Buy/Sell/Logout: ");
				userInput = kbd.nextLine();

				if(userInput.toUpperCase().equals(Constant.BUYER_ROLE)){
					System.out.println(currSessionUser.getUserName()+"### Product List: ");
					for(Product product : products) System.out.println(product.toString());
					//System.out.println("Add to Cart: ");
					//System.out.println("Buy ");
					//System.out.println("Order Confirmation Notification ");
					//System.out.println("Payment Receipt");
				}
				else if(userInput.equals(Constant.SELLER_ROLE)){
					System.out.println(currSessionUser.getUserName()+"### Product List: ");
					for(Product product: products){
						if(product.getOwner().equals(currSessionUser.getUserName())){
							System.out.println(product.toString());
						}
					}
					//System.out.println("System### Notification ");
					System.out.println(currSessionUser+"### Add/Edit/Delete Product: ");
					userInput = kbd.nextLine();
					if(userInput.toUpperCase().equals(Constant.ADD_PRODUCT)) registerProduct(currSessionUser);
				}
				else if(userInput.toUpperCase().equals(Constant.LOGOUT)){
					currSessionUser = null;
				}
			}
		}catch(Exception e) {e.printStackTrace();};
		}
	}

    static void signup(){
		System.out.println("#####Sign Up Page#####");
		System.out.println("Enter Username: ");
		String username = kbd.nextLine();
		System.out.println("Enter Email: ");
		String email = kbd.nextLine();
		System.out.println("Enter Password: ");
		String password = kbd.nextLine();
		System.out.println("Enter Address: ");
		String address = kbd.nextLine();
		
		User user = new User(username, email, password, address);
		users.add(user);
		System.out.println("Successfully registered your account!");
    }

    static void registerProduct(User user){
		System.out.println(user.getUserName()+"#####Product Registration Page#####");
		System.out.println("Enter Product Name: ");
		String productname = kbd.nextLine();
		System.out.println("Enter Description: ");
		String description = kbd.nextLine();
		System.out.println("Enter Price: ");
		Double price = kbd.nextDouble();
		System.out.println("Enter Inventory: ");
		Integer inventory = kbd.nextInt();

		Image image = new Image(productname+".png", "This is an image of product "+productname);
		
		Product product = new Product(productname, description, price, inventory, image, user.getUserName());
		products.add(product);
		System.out.println("Successfully registered new product!");
    }


    static void login(){
		System.out.println("#####Login Page#####");
		System.out.println("Enter User Name: ");
		String username = kbd.nextLine();
		System.out.println("Enter Password: ");
		String password = kbd.nextLine();
		
		boolean authenticated = false;
		for(User user : users){
			if(user.getUserName().equals(username) && user.getPassword().equals(password)){
			authenticated = true;
			System.out.println("Successfully logged in to the system!");
			currSessionUser = user;
			break;
			}
		}
		
		if(!authenticated) System.out.println("Unknown username or password! Please try again..");
    }
}

class Constant{
    public static final String SIGNUP = "SIGNUP";
    public static final String LOGIN = "LOGIN";
    public static final String BUYER_ROLE = "BUY";
    public static final String SELLER_ROLE = "SELL";
    public static final String LOGOUT = "LOGOUT";
    public static final String ADD_PRODUCT = "ADD";
}
