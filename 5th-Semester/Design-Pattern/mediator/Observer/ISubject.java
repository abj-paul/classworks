public interface ISubject {
    void attach(IObserver observer);
    void deattach(IObserver observer);
    EventOrState getState();
    void setState(EventOrState newState);
}
