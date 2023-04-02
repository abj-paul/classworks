package patterns;

public class Bitcoin extends PaymentMethod{
    private String bitcoinAuthId = "";
    private Double currentBitcoinRate = 0.0;

    Bitcoin(Double balance, String bitcoinAuthId) {
        super(balance);
        this.bitcoinAuthId = bitcoinAuthId;
    }

    private boolean validateCreditCardInformation(){
        contactWithServer(this.bitcoinAuthId);
        return true;
    }

    private void contactWithServer(String data){}
    private Double getCurrentBitcoinValue(){
        return Math.random();
    }

    @Override
    public String makePayment(Order order, Double amount) {
        this.currentBitcoinRate = getCurrentBitcoinValue();
        this.balance += balance*this.currentBitcoinRate;

        if(this.validateCreditCardInformation())
            if(this.checkIfAmountIsOk(order, amount))
                return this.generatePaymentReceipt(order, amount);
        return "Insufficient Amount or Wrong credit card information.";
    }
}
