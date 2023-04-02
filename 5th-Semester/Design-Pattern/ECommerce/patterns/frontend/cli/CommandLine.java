package patterns.frontend.cli;
import java.util.ArrayList;
import java.util.Scanner;

import patterns.*;

public class CommandLine {
    private User currSessionUser;
    Scanner kbd = new Scanner(System.in);
    String userInput;
    boolean sessionExit = false;
    Authentication authentication = Authentication.getAuthenticationInstance();

    public void showSystemTitleMessage(){
		System.out.println("#####Welcome to E-Commerce System#####");
    }

    private void login_signup_exit(){
        System.out.println("Login/Signup/Exit:");
        userInput = kbd.nextLine();
        if(userInput.toUpperCase().equals(Constant.SIGNUP)) {
            System.out.println("#####Sign Up Page#####");
            System.out.println("Enter Role(Buyer/Seller): ");
            String role = kbd.nextLine();
            System.out.println("Enter Username: ");
            String username = kbd.nextLine();
            System.out.println("Enter Email: ");
            String email = kbd.nextLine();
            System.out.println("Enter Password: ");
            String password = kbd.nextLine();
            System.out.println("Enter Address: ");
            String address = kbd.nextLine();

            authentication.registerAccount(username, password, email, address, role);
        }
        else if(userInput.toUpperCase().equals(Constant.LOGIN)){
            System.out.println("#####Login Page#####");
            System.out.println("Enter User Name: ");
            String username = kbd.nextLine();
            System.out.println("Enter Password: ");
            String password = kbd.nextLine();

            this.currSessionUser = this.authentication.login(username, password);

            if(currSessionUser instanceof Buyer && currSessionUser.getPaymentMethod()!=null){
                System.out.println("Enter Payment Method(Creditcard, Crypto): ");
                String paymentMethod = kbd.nextLine();
                System.out.println("Enter Initial Balance: ");
                Double balance = Double.parseDouble(kbd.nextLine());

                currSessionUser.setPaymentMethod(paymentMethod, balance);
            }

            if(this.currSessionUser==null) System.out.println("Unknown username or password! Please try again..");
        }
        else if(userInput.toUpperCase().equals("EXIT")){
            sessionExit = true;
                return;
        }
    }

    private void buyProduct(Buyer buyer){
        System.out.println(buyer.getUserName()+"### Product List: ");
        System.out.println(buyer.viewProducts());
        // Cart
        ArrayList<Order> cart = new ArrayList<Order>();
        System.out.println("Add to cart [Type \"DONE\" to finish]..");
        while(true){
            System.out.print("Product Id: ");
            String productId = kbd.nextLine();
            if(productId.toUpperCase().equals("DONE")) break;
            System.out.print("Number of Items: ");
            Integer amount = Integer.parseInt(kbd.nextLine());

            Order order = buyer.buy(Integer.parseInt(productId), amount);
            cart.add(order);
        }
        if(cart.size()!=0){
            System.out.println("Your cart is ready! Confirm buy...");
            for(Order order: cart) System.out.println(order.getProduct().toString()); // BUG FIX
            System.out.println("Confirm Purchase of all items of the Cart?[Y/n]");
            userInput = kbd.nextLine();
            if(userInput.toUpperCase().equals("Y")) {
                System.out.println("Notification has been sent to product owner. Wait for order Confirmation!");
            }
            else if(userInput.toUpperCase().equals("N")) {
                for(Order order: cart) buyer.removeOrder(order);
                System.out.println("Cart has been emptied.");
            }
        }
        cart.removeAll(cart);
    }

    private void payConfirmedOrders(Buyer buyer){
        ArrayList<Order> ordersWaitingForPayment = buyer.getConfirmedOrders();
        if(ordersWaitingForPayment.size()==0) return;
        for(int i=0; i<ordersWaitingForPayment.size(); i++){
            Order order = ordersWaitingForPayment.get(i);
            if(!order.isPaid()) {
                System.out.print(order.getProduct().toString() + "\nOrder for this product has been confirmed. Payment now?(Y/N)");
                userInput = kbd.nextLine();
                if(userInput.toUpperCase().equals("N")) continue;

                System.out.print("Select a Payment method (CreditCard, Crypto): ");
                userInput = kbd.nextLine();
                Double cost = order.getAmount()*order.getProduct().getPrice();
                buyer.pay(order.getOrderId(), cost);
            }
        }
    }

    private void buyerRole(){
        if(currSessionUser instanceof Seller){
            System.out.println("Login as Buyer to buy products!");
            return;
        }
        Buyer buyer = (Buyer)currSessionUser;

        if (currSessionUser.getNotificationsAsString().length() != 0) {
            System.out.println("System### Notification ");
            System.out.println(currSessionUser.getNotificationsAsString());
        }

        this.buyProduct(buyer);
        this.payConfirmedOrders(buyer);
    }

    private void confirmOrders(Seller seller) throws OrderNotFoundException{
        System.out.println(seller.getUserName()+" ### Confirm Order ###");	
        ArrayList<Order> completedOrders = seller.getPlacedOrders();
        if(completedOrders.size()==0)return;
        for(Order order : completedOrders){
            System.out.println(order.getProduct().getProductName()+", "+order.getAmount()+" [Y/N]: ");
            userInput = kbd.nextLine();
            if(userInput.toUpperCase().equals("Y")) seller.acceptOrder(order.getOrderId());
            else seller.rejectOrder(order.getOrderId());
        }
        System.out.println("Done handling all orders!");
    }

    private void registerProduct(Seller seller){
		System.out.println(seller.getUserName()+"#####Product Registration Page#####");
		System.out.println("Enter Product Name: ");
		String productname = kbd.nextLine();
		System.out.println("Enter Description: ");
		String description = kbd.nextLine();
		System.out.println("Enter Price: ");
		Double price = Double.parseDouble(kbd.nextLine());
		System.out.println("Enter Inventory: ");
		Integer inventory = Integer.parseInt(kbd.nextLine());

        seller.registerProduct(productname, description, price, inventory, seller);
		System.out.println("Successfully registered new product!");
    }

    private void sellerRole() throws OrderNotFoundException{
        if(currSessionUser instanceof Buyer){
            System.out.println("Login as Seller to sell products!");
            return;
        }
        Seller seller = (Seller)currSessionUser;

        if (currSessionUser.getNotificationsAsString().length() != 0) {
            System.out.println("System### Notification ");
            System.out.println(currSessionUser.getNotificationsAsString());
        }

        confirmOrders(seller);

        System.out.println(currSessionUser.getUserName()+"### Add/Edit/Delete Product: ");
        userInput = kbd.nextLine();
        if(userInput.toUpperCase().equals(Constant.ADD_PRODUCT)) registerProduct(seller);
    }

    public void totalFlow() throws OrderNotFoundException{
        while(!sessionExit){
            if(currSessionUser==null) login_signup_exit();
            else {
                System.out.println("Buy/Sell/LOGOUT: ");
                userInput = kbd.nextLine();
                if(userInput.toUpperCase().equals(Constant.BUYER_ROLE)) buyerRole();
                else if(userInput.toUpperCase().equals(Constant.SELLER_ROLE)) sellerRole();
                else if(userInput.toUpperCase().equals("LOGOUT")) currSessionUser=null;
                else System.out.println("Please enter a valid command!");
            }
        }
    }

    public static void main(String[] args) {
        CommandLine cmd = new CommandLine();
        cmd.showSystemTitleMessage();
        try{
            cmd.totalFlow();
        }catch(Exception e){e.printStackTrace();}
    }
}
