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

	public String getProductName(){
		return this.name;
	}

	public boolean decreaseInventory(int amount){
		if(amount>inventory) return false;
		this.inventory -= amount; // Handle exception
		return true;
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
	private ArrayList<String> notifications = null;
	private ArrayList<Order> orders = null; // Only for product owner

    User(String username, String email, String password, String address){
		this.username = username;
		this.email = email;
		this.password = password;
		this.address = address;
		this.notifications = new ArrayList<>();
		this.orders = new ArrayList<>();
    }

    public String getUserName(){
	return this.username;
    }

    public String getPassword(){
	return this.password;
    }

	public String toString(){
		return username+", "+email+", "+address;
	}

	public void notify(String message){
		notifications.add(message);
	}

	public void notifyOrder(Order order){
		orders.add(order);
	}

	public ArrayList<Order> getOrders() {
		return orders;
	}

	public void removeOrder(ArrayList<Order> order){
		this.orders.removeAll(order);
	}

	public String getNotifications(){
		String notifications_msg = "";

		for(String notification : notifications) notifications_msg += "-->"+notification + "\n";

		return notifications_msg;
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

class Order {
	private User buyer ;
	private User owner;
	private Product product;
	private int amount;
	private boolean orderConfirmed;

	Order(Product product, User buyer, int amount, User owner){
		this.product = product;
		this.buyer = buyer;
		this.amount = amount;
		this.owner = owner;
		this.orderConfirmed = false;
	}

	public void placeOrder(){
		owner.notify(this.toString());
		owner.notifyOrder(this);
	}

	public String toString(){
		return owner.getUserName()+" has ordered " + String.valueOf(amount) +" of " +  product.getProductName() + " from "+ owner.getUserName(); 
	}

	public int getAmount() {
		return amount;
	}
	public User getBuyer() {
		return buyer;
	}
	public User getOwner() {
		return owner;
	}

	public void confirmOrder(){
		this.orderConfirmed = true;
		buyer.notify(buyer.getUserName() + ", Your order for "+product.getProductName()+" has been confirmed!");
	}

	public Product getProduct() {
		return product;
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
			String userInput = null;
			System.out.println("#####Welcome to E-Commerce System#####");
		
			if(currSessionUser == null){
				System.out.println("Login/Signup/Exit:");
				userInput = kbd.nextLine();
				if(userInput.toUpperCase().equals(Constant.SIGNUP)) signup();
				else if(userInput.toUpperCase().equals(Constant.LOGIN)) login();
				else if(userInput.toUpperCase().equals("EXIT")) break;
			}
			else if(currSessionUser!=null){
				System.out.println("Buy/Sell/Logout: ");
				userInput = kbd.nextLine();

				if(userInput.toUpperCase().equals(Constant.BUYER_ROLE)){
					if (currSessionUser.getNotifications().length() != 0) {
						System.out.println("System### Notification ");
						System.out.println(currSessionUser.getNotifications());
						//System.out.println("Select Payment Method");
					}


					System.out.println(currSessionUser.getUserName()+"### Product List: ");
					for(Product product : products) System.out.println(product.toString());


					ArrayList<Order> cart = new ArrayList<Order>();
					System.out.println("Add to cart [Type \"DONE\" to finish]..");
					while(true){
						System.out.print("Product Name: ");
						String productName = kbd.nextLine();
						if(productName.toUpperCase().equals("DONE")) break;
						System.out.print("Number of Items: ");
						Integer amount = Integer.parseInt(kbd.nextLine());


						Product product = findProductFromName(productName);
						if(!product.decreaseInventory(amount)) {
							System.out.println("Insufficient inventory size! Inventory has less products");
							break;
						}

						User productOwner = findUserFromName(product.getOwner());
						Order order = new Order(product, currSessionUser, amount, productOwner);
						cart.add(order);
					}
					System.out.println("Your cart is ready! Confirm buy...");
					for(Order order: cart) System.out.println(order.getProduct().toString());
					System.out.println("Confirm Purchase of all items of the Cart?[Y/n]");
					userInput = kbd.nextLine();
					if(userInput.toUpperCase().equals("Y")) {
						for(Order order: cart){
							order.placeOrder();
						}
						System.out.println("Notification has been sent to product owner. Wait for order Confirmation!");
					}
					else if(userInput.toUpperCase().equals("N")) continue;
					//System.out.println("Order Confirmation Notification ");
					//System.out.println("Payment Receipt");
				}
				else if(userInput.toUpperCase().equals(Constant.SELLER_ROLE)){
					System.out.println(currSessionUser.getUserName()+"### Product List: ");
					for(Product product: products){
						if(product.getOwner().equals(currSessionUser.getUserName())){
							System.out.println(product.toString());
						}
					}
					if(currSessionUser.getNotifications().length()!=0){
						System.out.println("System### Notification ");

						System.out.println(currSessionUser.getNotifications());
						System.out.println(currSessionUser.getUserName()+" ### Confirm Order ###");
						
						ArrayList<Order> completedOrder = new ArrayList<>();
						for(Order order : currSessionUser.getOrders()){
							System.out.println(order.getProduct().getProductName()+", "+order.getAmount()+" [Y/N]: ");
							userInput = kbd.nextLine();
							if(userInput.toUpperCase().equals("Y")) {
								order.confirmOrder();
								completedOrder.add(order);
							}
						}

						currSessionUser.removeOrder(completedOrder);

						System.out.println("Done handling all orders!");
					}
					System.out.println(currSessionUser.getUserName()+"### Add/Edit/Delete Product: ");
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

	static Product findProductFromName(String productName){
		for(Product product: products){
			if(product.getProductName().toUpperCase().equals(productName.toUpperCase())){
				return product;
			}
		}
		return null;
	}

	static User findUserFromName(String userName){
		for(User user: users){
			if(user.getUserName().toUpperCase().equals(userName.toUpperCase())){
				return user;
			}
		}
		return null;
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
		Double price = Double.parseDouble(kbd.nextLine());
		System.out.println("Enter Inventory: ");
		Integer inventory = Integer.parseInt(kbd.nextLine());

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
