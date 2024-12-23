package hierarchy;

import helper.Topic;

public class Register extends Primitive {
    public Register(String nameOfEquip) {
        super(nameOfEquip);
    }

    Register(String nameOfEquip, Double discount, Double price, Double powercost){
        super(nameOfEquip, discount, price, powercost);
        this.price = calculateRegisterPrice();
    }

    private Double calculateSiliconAmount(){
        //fetch recent stats
        Double siliconAmountRequired = Math.random();
        return Math.max(this.price*siliconAmountRequired, this.price);
    }

    private Double calculateRegisterPrice(){
        return Math.max(calculateSiliconAmount(), this.price);
    }

    @Override
    public void setPrice(Double price){
        this.price = Math.max(price, this.calculateRegisterPrice());
    }

    @Override
    public boolean HandleHelp(Topic topic) {
        if(topic.getHelpTopic().equals("REGISTER")) {
            System.out.println("Here is help for REGISTER");
            return true;
        }
        return false;
    }
}
