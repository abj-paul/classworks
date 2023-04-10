package sorting;
import java.util.ArrayList;

import helper.Topic;
import hierarchy.Equipment;

public class SortableEquipment extends Equipment {
    private ArrayList<Equipment> components;
    private SortStrategy sortStrategy;

    SortableEquipment(String nameOfEquip) {
        super(nameOfEquip);
        this.components = new ArrayList<>();
        this.sortStrategy = new BubbleSort();
    }

    public SortableEquipment(String nameOfEquip, SortStrategy sortStrategy) {
        super(nameOfEquip);
        this.components = new ArrayList<>();
        this.sortStrategy = sortStrategy;
    }
    
    @Override
    public void addComponent(Equipment e) {
        this.components.add(e);
    }

    @Override
    protected void removeComponent(Equipment e) {
        this.components.remove(e);
    }

    @Override
    public boolean HandleHelp(Topic topic) {
        return false;
    }

    public void sort(){
        this.sortStrategy.setItems(components);
        this.sortStrategy.sort();
        this.components = this.sortStrategy.getSortedItems();
    }
    public void printSortedItems(){
        for(Equipment equipment : this.components){
            System.out.print(equipment.toString()+",");
        }
    }
    public void printTree() {
        System.out.println(this.toString());
        System.out.println();

        for(Equipment e : this.components) System.out.print(e.toString()+", ");
    }
}
