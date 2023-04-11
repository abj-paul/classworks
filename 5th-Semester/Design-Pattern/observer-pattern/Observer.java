public class Observer {
    private String observerName;
    Observer(String name){
        this.observerName = name;
    }

    public void update(SubjectState state){
        System.out.println(this.observerName + ": "+state.toString());
    }
}
