package builder;

import hierarchy.Cache;
import hierarchy.Equipment;
import hierarchy.Register;

public class CacheBuilder extends Builder{
    @Override
    Equipment build() {
        this.e  = new Cache("Cache");
        for(Equipment part : this.parts) e.addComponent(part);
        return e;
    }
    void addPrimitive(){
        this.parts.add(new Register("Register A8"));
    }
    
}
