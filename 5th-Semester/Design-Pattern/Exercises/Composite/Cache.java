public class Cache extends Composite{
    private final Double cacheFramePrice = 100.0;

    Cache(String nameOfEquip) {
        super(nameOfEquip);
    }

    @Override
    protected Double getNetPrice(){
        Double totalcost = 0.0;
        for(Equipment e : components){
            totalcost += e.getNetPrice();
            if(e instanceof Register) totalcost += 99*e.getNetPrice();
        }
        totalcost += cacheFramePrice;
        return totalcost;
    }
}
