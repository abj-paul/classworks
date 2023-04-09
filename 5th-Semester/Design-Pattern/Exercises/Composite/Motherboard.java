public class Motherboard extends Composite{


    Motherboard(String nameOfEquip) {
        super(nameOfEquip);
    }

    @Override
    public boolean HandleHelp(Topic topic) {
        if(topic.getHelpTopic().equals("Motherboard")){
            System.out.println("Here is the help for Motherboard.");
            return true;
        }
        for(Equipment component : this.components){
            boolean successfullyHandled = component.HandleHelp(topic);
            if(successfullyHandled) return true;
        }

        return false;
    }
}
