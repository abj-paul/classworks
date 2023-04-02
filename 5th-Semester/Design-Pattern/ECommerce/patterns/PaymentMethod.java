package patterns;

import java.security.MessageDigest;

public abstract class PaymentMethod {
    protected Double balance = 0.0;

    PaymentMethod(Double balance){
        this.balance = balance;
    }

    public abstract String makePayment(Order order, Double amount);

    protected boolean checkIfAmountIsOk(Order order, Double amount){
        if(amount>balance) return false;

        Double cost = order.getAmount() * order.getProduct().getPrice();
        if(cost>=amount) return true;
        else return false;
    }

    protected String generatePaymentReceipt(Order order, Double amount){
        String buyerName = order.getBuyer().getUserName();
        String sellerName = order.getProduct().getOwner().getUserName();
        String productName = order.getProduct().getProductName();
        String productAmount = Integer.toString(order.getAmount());
        String paymentHash = this.generatePaymentHash(order, amount);

        String receipt = "Payment Hash: "+paymentHash+"\n"+
                        "From: "+buyerName+"\n"+
                        "To: "+sellerName+"\n"+
                        "Product: "+productName+"\n"+
                        "Product Count: "+productAmount+"\n"+
                        "Payment Amount: "+amount+"\n";

        return receipt;
    }

    private String generatePaymentHash(Order order, Double amount){
        String stringToHash = order.toString() + Double.toString(amount), stringHash = null;

        try{
        MessageDigest messageDigest = MessageDigest.getInstance("SHA-256");
        messageDigest.update(stringToHash.getBytes());
        stringHash = new String(messageDigest.digest());
        }catch(Exception e){
            e.printStackTrace();
        }

        return stringHash;
    }
}
