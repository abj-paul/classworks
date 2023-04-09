import helper.HelpHandler;
import helper.Topic;
import hierarchy.ColorfulLaces;
import hierarchy.Desktop;
import hierarchy.Disk;
import hierarchy.Equipment;
import hierarchy.Motherboard;
import hierarchy.Ram;
import hierarchy.Register;
import hierarchy.Wire;
import sorting.BubbleSort;
import sorting.ConcreteMergeSort;
import sorting.MergeSort;
import sorting.SortableEquipment;

public class Client {
    public static void main(String[] args) {
        testStrategyAndTemplatePattern();
    }

    static void testStrategyAndTemplatePattern(){
        SortableEquipment equipment = new SortableEquipment("Sortable PC Components", new ConcreteMergeSort());

        Equipment register = new Register("Reg A3");
        Equipment wire = new Wire("Tamar Tar");
        Equipment disk = new Disk("Transend HDD");

        register.setPrice(10.0);
        wire.setPrice(50.0);
        disk.setPrice(1013.90);

        Equipment cache = new Disk("D2 Cache");
        cache.addComponent(register);
        cache.addComponent(wire);

        Equipment ram = new Ram("DDR2 RAM");
        ram.addComponent(register);

        Equipment motherboard = new Motherboard("Od Motherboard");
        motherboard.addComponent(cache);
        motherboard.addComponent(ram);
        motherboard.addComponent(wire);

        Equipment desktop = new Desktop("My PC Build!");
        desktop.addComponent(motherboard);
        desktop.addComponent(disk);
        desktop.addComponent(wire);
        desktop.addComponent(wire);

        equipment.addComponent(desktop);
        equipment.addComponent(motherboard);
        equipment.addComponent(ram);
        equipment.addComponent(cache);
        equipment.addComponent(wire);
        equipment.addComponent(disk);
        equipment.addComponent(register);
        equipment.sort();
        equipment.printSortedItems();
    }

    static void testCompositeAndHelper(){
        Equipment register = new Register("Reg A3");
        Equipment wire = new Wire("Tamar Tar");
        Equipment disk = new Disk("Transend HDD");

        register.setPrice(10.0);
        wire.setPrice(50.0);
        disk.setPrice(1013.90);

        Equipment cache = new Disk("D2 Cache");
        cache.addComponent(register);
        cache.addComponent(wire);

        Equipment ram = new Ram("DDR2 RAM");
        ram.addComponent(register);

        Equipment motherboard = new Motherboard("Od Motherboard");
        motherboard.addComponent(cache);
        motherboard.addComponent(ram);
        motherboard.addComponent(wire);

        Equipment desktop = new Desktop("My PC Build!");
        desktop.addComponent(motherboard);
        desktop.addComponent(disk);
        desktop.addComponent(wire);
                desktop.addComponent(wire);


        HelpHandler helpHandler = new HelpHandler(desktop);
        helpHandler.HandleHelp(new Topic("WIRE"));
        helpHandler.HandleHelp(new Topic("Motherboard"));
        helpHandler.HandleHelp(new Topic("SSD"));


        System.out.println("The price of your desktop build is: "+ desktop.getNetPrice());

        ColorfulLaces laces = new ColorfulLaces("Colorful laces");
        laces.addComponent(desktop);
        System.out.println("The price of your laces build is: "+ laces.getNetPrice());
    }
}
