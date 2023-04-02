package patterns;

import java.util.*;

public abstract class User {
    protected String username, email, password, address;
	protected ArrayList<String> notifications = null;
	protected Mediator mediator = null;
	PaymentMethod paymentMethod = null;

    User(String username, String email, String password, String address){
		this.username = username;
		this.email = email;
		this.password = password;
		this.address = address;
		this.notifications = new ArrayList<>();
		this.mediator = Mediator.getMediator();
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

	public void addNotification(String message){
		notifications.add(message);
	}

	public String getNotificationsAsString(){
		String notifications_msg = "";

		for(String notification : notifications) notifications_msg += "-->"+notification + "\n";

		return notifications_msg;
	}

	public PaymentMethod getPaymentMethod(){
		return this.paymentMethod;
	}

	public abstract void removeOrder(Order order);

	public void setPaymentMethod(String paymentType, Double balance){
		this.paymentMethod = this.mediator.createPaymentMethodAccount(this, paymentType, balance);
	}


/* 
	public void putOrderForPayment(Order order){
		ordersOnDelivery.add(order);
	}
	public void payment(Order order){
		ordersOnDelivery.remove(order);
	}

	public ArrayList<Order> getOrdersWaitingForPayment(){
		return ordersOnDelivery;
	}
	*/
}