package sorting;

import java.util.ArrayList;

import hierarchy.Equipment;

public abstract class SortStrategy implements ISort {
    ArrayList<Equipment> items;
    
    ArrayList<Equipment> getSortedItems(){
        return this.items;
    }
    void setItems(ArrayList<Equipment> items){
        this.items = items;
    }
}
