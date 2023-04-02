package patterns;
import java.util.ArrayList;

public class Seller extends User{

    Seller(String username, String email, String password, String address){
        super(username, email, password, address);
    }
    
    public void registerProduct(String name, String description, Double price, Integer inventory, Seller owner){
        Image image = new Image();
        this.mediator.registerNewProduct(name, description, price, inventory, image, owner);
    }

    public ArrayList<Order> getPlacedOrders(){
        return this.mediator.getOrders(this);
    }
    public void acceptOrder(Order order){
		super.mediator.addOrder(this, order);
	}
    public void rejectOrder(Order order){
		super.mediator.removeOrder(this, order);
	}
    public void removeOrder(Order order) {
		this.mediator.removeOrder(this, order);;
	}

    // Payment notification




}
