package hierarchy;

import helper.Topic;

public class Ram extends Composite implements IVersion {
    private String version;

    public Ram(String nameOfEquip) {
        super(nameOfEquip);
    }
    
    public void setVersion(String version){
        this.version = version;
    }
    public String getVersion(){
        return this.version;
    }

    @Override
    public boolean HandleHelp(Topic topic) {
        if(topic.getHelpTopic().equals("Ram")){
            System.out.println("Here is the help for Ram.");
            return true;
        }
        for(Equipment component : this.components){
            boolean successfullyHandled = component.HandleHelp(topic);
            if(successfullyHandled) return true;
        }

        return false;
    }

}
