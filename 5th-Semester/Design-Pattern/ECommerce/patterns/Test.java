package patterns;

public class Test {
    public static void main(String[] args){
        Authentication authentication = Authentication.getAuthenticationInstance();
        authentication.registerAccount("Abhijit Paul", "bsse1201@iit.du.ac.bd", "stu458", "Shanir Akhra, Dhaka", "seller");

        Seller seller = (Seller)authentication.login("Abhijit Paul", "stu458");
        seller.registerProduct("Basket", "A good apple basket from Barisal", 200.0, 1000, seller);


        authentication.registerAccount("Mashiat Amin Farin", "1202pass", "bsse1202@iit.du.ac.bd", "Boshundhara, Bangladesh", "buyer");
        Buyer buyer = (Buyer)authentication.login("Mashiat Amin Farin", "1202pass");

        buyer.viewProducts(); //sout
        buyer.buy(1, 10); //productId = 2

        seller.getNotificationsAsString(); //sout
        

    }
}
