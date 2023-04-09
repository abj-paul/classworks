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
    @Override
    public boolean HandleHelp(Topic topic) {
        if(topic.getHelpTopic().equals("Desktop")){
            System.out.println("Here is the help for desktop.");
            return true;
        }
        for(Equipment component : this.components){
            boolean successfullyHandled = component.HandleHelp(topic);
            if(successfullyHandled) return true;
        }

        return false;
    }
}
