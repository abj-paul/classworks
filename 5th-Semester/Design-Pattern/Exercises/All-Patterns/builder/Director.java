package builder;

import java.util.ArrayList;

import hierarchy.Desktop;
import hierarchy.Equipment;

public class Director {
    private Equipment fullObject;
    private ArrayList<Builder> builders;

    public Director(){
        this.builders = new ArrayList<>();
        builders.add(new CacheBuilder());
        builders.add(new DesktopBuilder());
        builders.add(new MotherboardBuilder());
        builders.add(new RAMBuilder());
        this.fullObject = new Desktop("Default Desktop Case");
    }

    public void build(ArrayList<String>parts){
        for(String part : parts){
            if(part.equals("Cache")) {
                Builder cacheBuilder = this.builders.get(0);
                cacheBuilder.addPrimitive();
                cacheBuilder.build();
                fullObject.addComponent(cacheBuilder.getEquipment());
            }else if(part.equals("Desktop")) {
                //pass
            }else if(part.equals("Motherboard")) {
                Builder motherboardBuilder = this.builders.get(2);
                motherboardBuilder.addPrimitive();
                motherboardBuilder.build();
                fullObject.addComponent(motherboardBuilder.getEquipment());
            }else if(part.equals("Ram")) {
                Builder ramdBuilder = this.builders.get(3);
                ramdBuilder.addPrimitive();
                ramdBuilder.build();
                fullObject.addComponent(ramdBuilder.getEquipment());
            }else {
                System.out.println("Parts not found in default director");
            }
        }
    }
    
    public Equipment getEquipment(){
        return this.fullObject;
    }

}
