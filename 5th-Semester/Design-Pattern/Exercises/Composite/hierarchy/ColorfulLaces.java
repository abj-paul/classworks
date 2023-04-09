package hierarchy;
import java.util.ArrayList;

import helper.Topic;

public class ColorfulLaces extends Equipment { 
    private ArrayList<Equipment> components;

    public ColorfulLaces(String nameOfEquip) {
        super(nameOfEquip);
        this.components = new ArrayList<>();
    }

    @Override
    public boolean HandleHelp(Topic topic) {
        //Do nothing
        return false;
    }

    @Override
    public void addComponent(Equipment e) {
        this.components.add(e);
    }

    @Override
    protected void removeComponent(Equipment e) {
        this.components.add(e);
    }
    
    @Override
    public Double getNetPrice(){
        Double netprice = 53.0;
        for(Equipment equipment : components){
            netprice += equipment.getNetPrice();
        }
        this.price  = netprice;
        return this.price;
    }
}
