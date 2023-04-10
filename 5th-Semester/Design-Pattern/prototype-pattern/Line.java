import java.util.ArrayList;

public class Line implements IProduct {

    private ArrayList<IProduct> components;
    private Integer length;
    private String name;

    Line(String name){
        this.components = new ArrayList<>();
        this.length = 10;
        this.name = name;
    }
    Line(IProduct lineObj){
        this.components = lineObj.getComponents();
        this.length = lineObj.getLength();
        this.name = "Copied "+lineObj.getName();
    }
    @Override
    public Integer getLength() {
        return this.length;
    }
    public ArrayList<IProduct> getComponents() {
        return components;
    }

    public String getName() {
        return name;
    }

    @Override
    public IProduct myclone() {
        return new Line(this);
    }
}
