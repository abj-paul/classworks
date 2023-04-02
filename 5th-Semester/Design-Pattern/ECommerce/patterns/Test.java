package patterns;

public class Test {
    public static void main(String[] args){
        Authentication authentication = Authentication.getAuthenticationInstance();
        authentication.registerAccount("Abhijit Paul", "stu458", "bsse1201@iit.du.ac.bd", "Shanir Akhra, Dhaka", "seller");

        Seller seller = (Seller)authentication.login("Abhijit Paul", "stu458");
        seller.registerProduct("Basket", "A good apple basket from Barisal", 200.0, 1000, seller);


        authentication.registerAccount("Mashiat Amin Farin", "1202pass", "bsse1202@iit.du.ac.bd", "Boshundhara, Bangladesh", "buyer");
        Buyer buyer = (Buyer)authentication.login("Mashiat Amin Farin", "1202pass");
        buyer.setPaymentMethod("CREDITCARD", 20000.0);

        System.out.println(buyer.viewProducts());
        buyer.buy(1, 10); //productId = 2

        System.out.println(seller.getNotificationsAsString());
        try{
            seller.acceptOrder(1);
        }catch(OrderNotFoundException e) {
            e.printStackTrace();
        }

        System.out.println(buyer.getNotificationsAsString());
        System.out.println(buyer.getConfirmedOrders());
        System.out.println(buyer.pay(1, 100.0));
    }
}
