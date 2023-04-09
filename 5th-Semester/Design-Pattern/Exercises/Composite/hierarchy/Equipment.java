package hierarchy;
import helper.IHelp;

public abstract class Equipment implements IHelp, Comparable {
    protected String nameOfEquip;
    protected Double price, discount, powerCost;

    public Equipment(String nameOfEquip){
        this.nameOfEquip = nameOfEquip;
        this.price = 0.0;
        this.discount = 0.0;
        this.powerCost = 0.0;
    }

    public Double getNetPrice(){
        return this.price;
    }
    public void setPrice(Double price){
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

    public abstract void addComponent(Equipment e);
    protected abstract void removeComponent(Equipment e);

    @Override
    public int compareTo(Object o){
        Equipment eqp = (Equipment)o;
        if(eqp.getNetPrice() >= this.getNetPrice()) return 1;
        else return -1;
    }
    @Override
    public String toString() {
        return nameOfEquip+"("+price+") ";
    }
}