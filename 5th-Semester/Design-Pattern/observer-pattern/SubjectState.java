public class SubjectState {
    private String eventName = "";

    SubjectState(String eventName){
        this.eventName = eventName;
    }

    @Override
    public String toString() {
        return "Event: "+ this.eventName;
    }
}
