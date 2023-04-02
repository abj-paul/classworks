package patterns;

public class Product {
    private String name, description;
    private Integer productId, inventory;
    private Double price;
    private Image image;
    Seller owner;

    Product(String name, String description, Double price, Integer inventory, Image image, Seller owner, Integer productId ){
		this.name = name;
		this.description = description;
		this.price = price;
		this.inventory = inventory;
		this.image = image;
		this.owner = owner;
        this.productId = productId;
    }

    public Integer getProductId(){
        return this.productId;
    }

	public String getName() {
		return name;
	}

    public User getOwner(){
	    return this.owner;
    }

	public String getProductName(){
		return this.name;
	}

    public Double getPrice() {
		return price;
	}

    @Override
    public String toString(){
	return "----"+this.name+"----\n"+ this.description + "\nPrice" + String.valueOf(price) +"\nInventory: "+ String.valueOf(inventory) + "\n Image: "+image+"\n";
    }

    public boolean decreaseInventory(int amount){
		if(amount>inventory) return false;
		this.inventory -= amount; // Handle exception
		return true;
	}
}
