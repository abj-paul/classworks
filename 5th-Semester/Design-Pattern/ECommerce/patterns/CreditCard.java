package patterns;

public class CreditCard extends PaymentMethod{
    private String creditCardInfo = "";

    CreditCard(Double balance, String creditCardInfo) {
        super(balance);
        this.creditCardInfo = creditCardInfo;
    }

    private boolean validateCreditCardInformation(){
        contactWithServer(this.creditCardInfo);
        return true;
    }

    void contactWithServer(String data){}

    @Override
    public String makePayment(Order order, Double amount) {
        if(this.validateCreditCardInformation())
            if(this.checkIfAmountIsOk(order, amount))
                return this.generatePaymentReceipt(order, amount);
        return "Insufficient Amount or Wrong credit card information.";
    }
    
}
