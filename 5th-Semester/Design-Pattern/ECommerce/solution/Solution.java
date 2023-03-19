package solution;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.*;

class Commands {
	private String userInput = null;
	public void showSystemTitleMessage(){
		System.out.println("#####Welcome to E-Commerce System#####");
	}
}

public class Solution {
    static ArrayList<User> users = new ArrayList<User>();
    static ArrayList<Product> products = new ArrayList<Product>();
    static Scanner kbd = new Scanner(System.in);

    public static void main(String[] args){
		Commands commands = new Commands();
		static User currSessionUser = null;
	
		while(true){
		try{
			commands.showSystemTitleMessage();
			
			
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
					if(cart.size()!=0){
						System.out.println("Your cart is ready! Confirm buy...");
						for(Order order: cart) System.out.println(order.getProduct().toString()); // BUG FIX
						System.out.println("Confirm Purchase of all items of the Cart?[Y/n]");
						userInput = kbd.nextLine();
						if(userInput.toUpperCase().equals("Y")) {
							for(Order order: cart){
								order.placeOrder();
							}
							System.out.println("Notification has been sent to product owner. Wait for order Confirmation!");
						}
						else if(userInput.toUpperCase().equals("N")) continue;
					}


					//System.out.println("Payment Receipt"); TODO
					ArrayList<Order> ordersWaitingForPayment = currSessionUser.getOrdersWaitingForPayment();
					for(int i=0; i<ordersWaitingForPayment.size(); i++){
						Order order = ordersWaitingForPayment.get(i);
						if(!order.isPaid()) {
							System.out.print(order.getProduct().toString() + "\nOrder for this product has been confirmed. Payment now?(Y/N)");
							userInput = kbd.nextLine();
							if(userInput.toUpperCase().equals("N")) continue;

							System.out.print("Select a Payment method (Paypal, Bkash, Rocket): ");
							userInput = kbd.nextLine();
							Payment payment = new Payment(userInput);
							order.pay(payment);
						}
					}
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
