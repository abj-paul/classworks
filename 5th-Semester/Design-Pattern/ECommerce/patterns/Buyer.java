package patterns;
import java.util.ArrayList;

public class Buyer extends User{
    Buyer(String username, String email, String password, String address){
        super(username, email, password, address);
    }

    public String viewProducts(){ // may require edit. getProdudctList()
        return this.mediator.getProductListAsString();
    }

    public Order buy(Integer productId, Integer amount){
        Product product  = this.mediator.findProductFromId(productId);
        if(product.getInventory()<amount) return null;
        product.decreaseInventory(amount);
        Order order = new Order(product, this, amount, this.mediator.generateNewOrderId());
        this.addOrder(order);

        return order;
    }

    private void addOrder(Order order){
		this.mediator.addOrder(this, order);;
	}

    public String getConfirmedOrdersAsString(){
        ArrayList<Order> confirmedOrders = this.mediator.getOrders(this);
        String confirmedOrdersStr = "";
        for(Order order : confirmedOrders) confirmedOrdersStr += order.toString() +"\n";
        return confirmedOrdersStr;
    }

    public ArrayList<Order> getConfirmedOrders(){
        return this.mediator.getOrders(this);
    }

    public String pay(Integer orderId, Double amount){
        Order order = null;
        try{
            order =  mediator.findOrderFromId(this, orderId);
            return this.mediator.payment_interactions(order, amount);
        }catch(OrderNotFoundException e){e.printStackTrace();}
        return "Error occurred when paying for order "+orderId;
    }

    public void removeOrder(Order order) {
		this.mediator.removeOrder(this, order);
	}
}


    



