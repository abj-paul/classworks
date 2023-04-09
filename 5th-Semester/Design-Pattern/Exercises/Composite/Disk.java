public class Disk extends Primitive{
    Disk(String nameOfEquip) {
        super(nameOfEquip);
    }

    Disk(String nameOfEquip, Double discount, Double price, Double powercost){
        super(nameOfEquip, discount, price, powercost);
        this.price = calculateMagnetPrice();
    }

    private Double calculateSiliconAmount(){
        //fetch recent stats
        Double siliconAmountRequired = Math.random();
        return Math.max(this.price*siliconAmountRequired, this.price);
    }

    private Double calculateMagnetPrice(){
        return Math.max(calculateSiliconAmount(), this.price);
    }

    @Override
    protected void setPrice(Double price){
        this.price = Math.max(price, this.calculateMagnetPrice());
    }
}
