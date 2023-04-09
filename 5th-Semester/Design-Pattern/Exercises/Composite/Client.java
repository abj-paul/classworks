public class Client {
    public static void main(String[] args) {
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

        System.out.println("The price of your desktop build is: "+ desktop.getNetPrice());

    }
}
