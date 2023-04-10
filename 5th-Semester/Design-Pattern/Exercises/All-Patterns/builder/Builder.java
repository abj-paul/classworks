package builder;

import java.util.ArrayList;

import hierarchy.Equipment;

public abstract class Builder {
    protected ArrayList<Equipment> parts = new ArrayList<>();
    protected Equipment e;

    protected void setParts(ArrayList<Equipment> parts){
        this.parts = parts;
    }
    public Equipment getEquipment(){
        this.parts.clear();
        return e;
    }
    abstract Equipment build();
    abstract void addPrimitive();
}
