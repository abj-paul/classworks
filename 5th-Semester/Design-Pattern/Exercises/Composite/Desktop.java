public class Desktop extends Composite{
    private Double FramePrice = 100.0;

    Desktop(String nameOfEquip) {
        super(nameOfEquip);
    }
    @Override
    protected Double getNetPrice(){
        Double totalcost = 0.0;
        for(Equipment e : components){
            totalcost += e.getNetPrice();
        }
        totalcost += FramePrice;
        return totalcost;
    }
}
