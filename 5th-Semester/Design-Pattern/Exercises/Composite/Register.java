public class Register extends Primitive {
    Register(String nameOfEquip) {
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
    protected void setPrice(Double price){
        this.price = Math.max(price, this.calculateRegisterPrice());
    }
}
