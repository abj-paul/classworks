package solution;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.*;


public class Product {
    private String name, description, owner;
    private Integer inventory;
    private Double price;
    private Image image;

    Product(String name, String description, Double price, Integer inventory, Image image, String owner ){
		this.name = name;
		this.description = description;
		this.price = price;
		this.inventory = inventory;
		this.image = image;
		this.owner = owner;
    }

	public String getName() {
		return name;
	}

    public String getOwner(){
	return this.owner;
    }

	public String getProductName(){
		return this.name;
	}

	public boolean decreaseInventory(int amount){
		if(amount>inventory) return false;
		this.inventory -= amount; // Handle exception
		return true;
	}

    @Override
    public String toString(){
	return "----"+this.name+"----\n"+ this.description + "\nPrice" + String.valueOf(price) +"\nInventory: "+ String.valueOf(inventory) + "\n Image: "+image+"\n";
    }

	public Double getPrice() {
		return price;
	}
}
