package solution;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.*;

class Order {
	private User buyer ;
	private User owner;
	private Product product;
	private int amount;
	private boolean orderConfirmed;
	private boolean paid;

	Order(Product product, User buyer, int amount, User owner){
		this.product = product;
		this.buyer = buyer;
		this.amount = amount;
		this.owner = owner;
		this.orderConfirmed = false;
		this.paid = false;
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
		buyer.putOrderForPayment(this);
	}

	public Product getProduct() {
		return product;
	}
	public void pay(Payment paymentMethod){
		if(paymentMethod.pay(this)==false){
			System.out.println("Insufficient amount! Can't complete payment.");
			return;
		}
		this.paid = true;
		buyer.notify(paymentMethod.generatePaymentReceipt(this));
		buyer.payment(this);
		System.out.println("Successfully paid for the order "+this.toString());
	}

	public boolean isPaid(){
		return paid;
	}
}

