public abstract class Equipment {
    protected String nameOfEquip;
    protected Double price, discount, powerCost;

    Equipment(String nameOfEquip){
        this.nameOfEquip = nameOfEquip;
        this.price = 0.0;
        this.discount = 0.0;
        this.powerCost = 0.0;
    }

    protected Double getNetPrice(){
        return this.price;
    }
    protected void setPrice(Double price){
        this.price = price;
    }
    protected Double getDiscount(){
        return this.discount;
    }
    protected void setDiscount(Double discount){
        this.discount = discount;
    }
    protected Double getPowerCost(){
        return this.powerCost;
    }
    protected void setPowerCost(Double powerCost){
        this.powerCost = powerCost;
    }

    protected abstract void addComponent(Equipment e);
    protected abstract void removeComponent(Equipment e);
}