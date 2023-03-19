package solution;

import java.util.*;

public class User {
    private String username, email, password, address;
	private ArrayList<String> notifications = null;
	private ArrayList<Order> orders = null; // Only for product owner
	private ArrayList<Order> ordersOnDelivery = null; // customer

    User(String username, String email, String password, String address){
		this.username = username;
		this.email = email;
		this.password = password;
		this.address = address;
		this.notifications = new ArrayList<>();
		this.orders = new ArrayList<>();
		this.ordersOnDelivery = new ArrayList<>();
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
	public void putOrderForPayment(Order order){
		ordersOnDelivery.add(order);
	}
	public void payment(Order order){
		ordersOnDelivery.remove(order);
	}

	public ArrayList<Order> getOrdersWaitingForPayment(){
		return ordersOnDelivery;
	}
}
