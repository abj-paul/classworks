package solution;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.*;

public abstract class Payment {
	private Double money;
	private String payment_method;

	Payment(Double initialMoney){
		this.money = initialMoney;
	}

    public String generatePaymentReceipt(Order order){
		String timeStamp = new SimpleDateFormat("yyyyMMdd_HHmmss").format(Calendar.getInstance().getTime());
		return timeStamp +": "+ order.getAmount()*order.getProduct().getPrice() +" taka has been paid for "+order.getProduct().getName() + " using "+payment_method;
    }

	// How do I differentiate notificaitons?

	abstract Double convertPaymentMethodToTaka(Double amount);
	abstract String getPaymentMethodName();

	public boolean pay(Order order){
		System.out.println("Contacting with "+ payment_method +" to perform payment.");
		Double purchaseAmount = order.getProduct().getPrice() * order.getAmount();
		if(convertTakaToPaymentMethodpurchaseAmount>money) return false;
		else money -= convertPaymentMethodToTaka(purchaseAmount);
		return true;
	}
}

class CreditCard extends Payment {

	CreditCard(Double initialMoney) {
		super(initialMoney);
	}

	@Override
	Double convertPaymentMethodToTaka(Double amount){
		Double creditPayment = 0;
		creditPayment = amount*2;
		return creditPayment;
	}

	@Override
	String getPaymentMethodName(){
		return "Credit Card";
	}
}

class Paypal extends Payment {

	Paypal(Double initialMoney) {
		super(initialMoney);
	}

	@Override
	Double convertPaymentMethodToTaka(Double amount){
		Double creditPayment = 0;
		creditPayment = amount*1;
		return creditPayment;
	}

	@Override
	String getPaymentMethodName(){
		return "Paypal";
	}

}

class cryptocurrency extends Payment {
	cryptocurrency(Double initialMoney) {
		super(initialMoney);
	}

	@Override
	Double convertPaymentMethodToTaka(Double amount){
		Double creditPayment = 0;
		creditPayment = amount*10;
		return creditPayment;
	}

	@Override
	String getPaymentMethodName(){
		return "Cryptocurrency";
	}
}