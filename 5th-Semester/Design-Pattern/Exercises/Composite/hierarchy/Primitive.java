package hierarchy;
public abstract class Primitive extends Equipment{

    Primitive(String nameOfEquip) {
        super(nameOfEquip);
    }

    Primitive(String nameOfEquip, Double discount, Double price, Double powerCost){
        super(nameOfEquip);
        this.discount = discount;
        this.price = price;
        this.powerCost = powerCost;
    }

    @Override
    public void addComponent(Equipment e) {
        // perform no operation. A secueiry loophole, yes. But in composite pattern, we prefer transparency over security.
    }

    @Override
    protected void removeComponent(Equipment e) {
        // perform no operation
    }

    public void printTree() {
        System.out.println(this.toString());
        System.out.println();
    }

}
