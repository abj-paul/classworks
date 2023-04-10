import javax.swing.plaf.nimbus.State;

public class Mediator implements IObserver {

    private EventOrState currentState;

    Mediator(){
        this.currentState = new EventOrState();
    }

    @Override
    public void update(EventOrState state) {
        this.currentState = state;
    }

    private void handleStateChange(){
        
    }
    
}
