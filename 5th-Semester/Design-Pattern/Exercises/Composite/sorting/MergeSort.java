package sorting;

import hierarchy.Equipment;

public abstract class MergeSort extends SortStrategy { 
  
    abstract protected int divide(int left, int right);
    abstract protected void merge(int left, int middle, int right);

    final void sort(int left, int right){
        int middle = divide(left, right);
        if(middle==right) return;
        sort(left, middle);
        sort(middle+1, right);
        merge(left, middle, right);
    }

    public void sort(){
        this.sort(0, this.items.size()-1);
    }
}
