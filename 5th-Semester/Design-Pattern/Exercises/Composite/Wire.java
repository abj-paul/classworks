public class Wire extends Primitive {

    Wire(String nameOfEquip) {
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
}
