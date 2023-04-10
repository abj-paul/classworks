package sorting;

import java.util.ArrayList;

import hierarchy.Equipment;

public class BubbleSort extends SortStrategy{
    @Override
    public void sort() {
        for(int i=0; i<items.size(); i++){
            for(int j=i+1; j<items.size(); j++){
                if(items.get(i).compareTo(items.get(j))==-1){
                    Equipment temp = items.get(i);
                    items.set(i, items.get(j));
                    items.set(j, temp);
                }
            }
        }
    }
    
}
