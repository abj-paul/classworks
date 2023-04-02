package patterns;

import java.util.ArrayList;

public class Mediator {
    ArrayList<Order> requestedOrders, confirmedOrders, paidOrders;
    ArrayList<Product> registeredProducts;
    private Integer orderId = 0;
    private static Mediator mediatorInstance = null;

    private Mediator(){
        this.requestedOrders = new ArrayList<>();
        this.confirmedOrders = new ArrayList<>();
        this.paidOrders = new ArrayList<>();
        this.registeredProducts = new ArrayList<>();
    }

    public static Mediator getMediator(){
        if(mediatorInstance==null) mediatorInstance = new Mediator();
        return mediatorInstance;
    }

    // Shared Data
    public String getProductListAsString(){
        String productListStr = "";
        for(Product product : registeredProducts) productListStr += product.toString()+"\n";
        return productListStr;
    }

    public Order findOrderFromId(User user, Integer orderId) throws OrderNotFoundException{
        if(user instanceof Seller){
           for(Order order : requestedOrders){
                if(order.getOrderId()==orderId) return order;
            }
        }else if(user instanceof Buyer){
            for(Order order : confirmedOrders){
                if(order.getOrderId().equals(orderId)) return order;
            }
        }
        throw new OrderNotFoundException(Integer.toString(orderId));
    }

    public Integer generateNewOrderId(){
        this.orderId++;
        return this.orderId;
    }

    public Product findProductFromId(Integer productId){
        for(Product product : registeredProducts) {
            if(product.getProductId()==productId) return product;
        }
        return null;
    }

    // Fascilitate Communication
    
    public void addOrder(User user, Order order){
        if(user instanceof Buyer) {
            String buyer = user.getUserName();
            Integer amount = order.getAmount(); 
            String productName = order.getProduct().getProductName();

            String orderNotification = buyer+" has ordered "+amount+" amount of "+ productName+".";
            order.getOwner().addNotification(orderNotification);
            requestedOrders.add(order);
        }
        else if(user instanceof Seller){
            String seller = user.getUserName();
            Integer amount = order.getAmount(); 
            String productName = order.getProduct().getProductName();

            String orderConfirmationNotification = seller+" has confirmed the order of "+ productName+" for the amount of "+amount+".";
            order.getBuyer().addNotification(orderConfirmationNotification);

            requestedOrders.remove(order);
            confirmedOrders.add(order);
        }
    }

    public ArrayList<Order> getOrders(User user){
        if(user instanceof Seller){
            ArrayList<Order> requestedOrdersForUser = new ArrayList<>();
            for(Order order : this.requestedOrders){
                if(order.getOwner().equals(user)) requestedOrdersForUser.add(order);
            }
            return requestedOrdersForUser;
        }else if(user instanceof Buyer){
            ArrayList<Order> confirmedOrdersForBuyer = new ArrayList<>();
            for(Order order: confirmedOrders){
                if(order.getBuyer().equals(user)) confirmedOrdersForBuyer.add(order);
            }
            return confirmedOrdersForBuyer;
        }
        
        return null; // Error has occcurred
    }

    public void removeOrder(User user, Order order){
        if(user instanceof Seller){
            if(this.confirmedOrders.remove(order)==false){ // seller has not confirmed the order yet
                this.requestedOrders.remove(order);
                String productName = order.getProduct().getProductName();
                String orderRejectionNotification = "Your order for the product "+productName + " has been rejected!";
                order.getBuyer().addNotification(orderRejectionNotification);
            }else {
                String orderDeletionNotification = "Seller has deleted their order confirmation for the order "+order.toString();
                order.getBuyer().addNotification(orderDeletionNotification);
            }
        }else if(user instanceof Buyer){
            this.requestedOrders.remove(order);
            String productName = order.getProduct().getProductName();
            String orderDeletionNotification = "Buyer has removed their order for the item "+ productName;
            order.getOwner().addNotification(orderDeletionNotification);
        }
    }

    public PaymentMethod createPaymentMethodAccount(User user, String paymentType,Double balance){
        if(paymentType.toUpperCase().equals("CREDITCARD")) return new CreditCard(balance, user.toString());
        else if(paymentType.toUpperCase().equals("BITCOIN")) return new Bitcoin(balance, user.toString());
        else return null;
    }

    public void registerNewProduct(String name, String description, Double price, Integer inventory, Image image, Seller owner){
        Product product = new Product(name, description, price, inventory, image, owner, this.registeredProducts.size()+1);
        this.registeredProducts.add(product);
        
        Authentication authentication = Authentication.getAuthenticationInstance();
        authentication.notifyAllUsers("A new product "+name+" is available now!");
    }

    public String payment_interactions(Order order, Double amount){
        if(order.getBuyer().getPaymentMethod()==null) return Constant.SET_PAYMENT_METHOD_FIRST;

        String receipt = order.getBuyer().getPaymentMethod().makePayment(order, amount);
        if(receipt.equals(Constant.WRONG_PAYMENT_CREDENTIALS)) return receipt;

        this.confirmedOrders.remove(order);
        this.paidOrders.add(order);

        order.getBuyer().addNotification(receipt);
        order.getProduct().getOwner().addNotification(receipt);

        return receipt;
    }

}
