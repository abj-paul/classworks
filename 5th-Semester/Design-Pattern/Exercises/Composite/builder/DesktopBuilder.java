package builder;

import hierarchy.Desktop;
import hierarchy.Disk;
import hierarchy.Equipment;
import hierarchy.Wire;

public class DesktopBuilder extends Builder {
    @Override
    Equipment build() {
        this.e = new Desktop("Motherboard");
        for(Equipment part : this.parts) e.addComponent(part);
        return e;
    }

    @Override
    void addPrimitive() {
        this.parts.add(new Wire("Tamar Tar"));
        this.parts.add(new Disk("HDD A01"));
    }
}
