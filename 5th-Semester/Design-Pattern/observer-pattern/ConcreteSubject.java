public class ConcreteSubject extends Subject{

    @Override
    public void setState(SubjectState state) {
        this.state = state;
        this.notifyAllSubscriber();
    }

    @Override
    public SubjectState getState() {
        return this.state;
    }
    
}
