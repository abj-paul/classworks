package hierarchy;

import helper.Topic;

public class Wire extends Primitive {

    public Wire(String nameOfEquip) {
        super(nameOfEquip);
    }

    Wire(String nameOfEquip, Double discount, Double price, Double powercost){
        super(nameOfEquip, discount, price, powercost);
        this.price = calculateTamaPrice();
    }

    private Double calculateTamaPrice(){
        //fetch recent stats
        Double tamaPrice = Math.random();
        return Math.max(this.price*tamaPrice, this.price);
    }

    @Override
    public boolean HandleHelp(Topic topic) {
        if(topic.getHelpTopic().equals("WIRE")) {
            System.out.println("Here is help for WIRE");
            return true;
        }
        return false;
    }
}
