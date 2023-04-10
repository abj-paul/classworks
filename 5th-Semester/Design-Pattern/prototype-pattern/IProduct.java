import java.util.ArrayList;

public interface IProduct extends IPrototype{

    ArrayList<IProduct> getComponents();
    String getName();
    Integer getLength();
    
}
