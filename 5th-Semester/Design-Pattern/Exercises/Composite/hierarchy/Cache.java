package hierarchy;

import helper.Topic;

public class Cache extends Composite{
    private final Double cacheFramePrice = 100.0;

    public Cache(String nameOfEquip) {
        super(nameOfEquip);
    }

    @Override
    public Double getNetPrice(){
        Double totalcost = 0.0;
        for(Equipment e : components){
            totalcost += e.getNetPrice();
            if(e instanceof Register) totalcost += 99*e.getNetPrice();
        }
        totalcost += cacheFramePrice;
        return totalcost;
    }

    @Override
    public boolean HandleHelp(Topic topic) {
        if(topic.getHelpTopic().equals("Cache")){
            System.out.println("Here is the help for Cache.");
            return true;
        }
        for(Equipment component : this.components){
            boolean successfullyHandled = component.HandleHelp(topic);
            if(successfullyHandled) return true;
        }

        return false;
    }
}
