package builder;

import hierarchy.Equipment;
import hierarchy.Ram;
import hierarchy.Register;

public class RAMBuilder extends Builder{
    @Override
    Equipment build() {
        this.e = new Ram("Ram");
        for(Equipment part : this.parts) e.addComponent(part);
        return e;
    }

    @Override
    void addPrimitive() {
        this.parts.add(new Register("Register A7"));
    }
}
