package builder;

import hierarchy.ColorfulLaces;
import hierarchy.Equipment;
import hierarchy.Motherboard;
import hierarchy.Wire;

public class MotherboardBuilder extends Builder{

    @Override
    Equipment build() {
        this.e = new Motherboard("Motherboard");
        for(Equipment part : this.parts) e.addComponent(part);
        return e;
    }

    @Override
    void addPrimitive() {
        this.parts.add(new Wire("Tamar Tar"));
        //this.parts.add(new ColorfulLaces("Nice Laces"));
    }
    
}
