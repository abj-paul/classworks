package hierarchy;
import java.util.ArrayList;

public abstract class Composite extends Equipment {
    protected ArrayList<Equipment> components;

    Composite(String nameOfEquip){
        super(nameOfEquip);
        this.components = new ArrayList<Equipment>();
    }

    @Override
    public void addComponent(Equipment e) {
        this.components.add(e);
    }

    @Override
    protected void removeComponent(Equipment e) {
        this.components.remove(e);
    }

    @Override
    public Double getNetPrice(){
        Double netprice = 0.0;
        for(Equipment equipment : components){
            netprice += equipment.getNetPrice();
        }
        this.price  = netprice;
        return this.price;
    }

    @Override
    protected Double getPowerCost(){
        Double netpowercost = 0.0;
        for(Equipment equipment : components) netpowercost += equipment.getPowerCost();
        this.powerCost = netpowercost;
        return this.powerCost;
    }

    @Override
    public String toString() {
        return nameOfEquip+"("+this.getNetPrice()+") ";
    }
    
}
