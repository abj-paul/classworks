public class HelpHandler implements IHelp{
    private Equipment successor;
    HelpHandler(Equipment successor){
        this.successor = successor;
    }

    public boolean HandleHelp(Topic topic) {
        boolean successfulHelp = successor.HandleHelp(topic);
        if(!successfulHelp) {
            System.out.println("No help found for the topic "+topic.getHelpTopic());
            return false;
        }
        return true;
    }

}
