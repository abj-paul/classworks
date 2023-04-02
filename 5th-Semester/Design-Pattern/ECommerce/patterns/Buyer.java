package patterns;
import java.util.ArrayList;

public class Buyer extends User{
    Buyer(String username, String email, String password, String address){
        super(username, email, password, address);
    }

    public String viewProducts(){ // may require edit. getProdudctList()
        return this.mediator.getProductListAsString();
    }

    public void buy(Integer productId, Integer amount){
        Product product  = this.mediator.findProductFromId(productId);
        Order order = new Order(product, this, amount);
        this.addOrder(order);
    }
    public void buy(String productName){

    }

    private void addOrder(Order order){
		this.mediator.addOrder(this, order);;
	}

    public ArrayList<Order> getConfirmedOrders(){
        ArrayList<Order> confirmedOrders = this.mediator.getOrders(this);
        return confirmedOrders;
    }

    // Pay

    public void removeOrder(Order order) {
		this.mediator.removeOrder(this, order);
	}
}


    



