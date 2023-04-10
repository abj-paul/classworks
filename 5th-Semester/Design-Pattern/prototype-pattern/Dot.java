import java.util.ArrayList;

public class Dot implements IProduct{
    private Integer length;
    private String name;

    public Dot(String name){
        this.name = name;
        this.length = 0;
    }

    @Override
    public IProduct myclone() {
        return null;
    }

    @Override
    public ArrayList<IProduct> getComponents() {
        return new ArrayList<>();
    }

    @Override
    public String getName() {
        return this.name;
    }

    @Override
    public Integer getLength() {
        return this.length;
    }
    
}
