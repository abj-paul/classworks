package sorting;

import hierarchy.Equipment;

public class ConcreteMergeSort extends MergeSort{
    private Equipment[] tempArray;

    public ConcreteMergeSort(){
        this.tempArray = new Equipment[100];
    }

    protected int divide(int left, int right) {
        if (left < right) {
            int middle = (left + right) / 2;
            divide(left, middle);
            divide(middle + 1, right);
            return middle;
        }
        return right;
    }

    protected void merge(int left, int middle, int right) {
        for (int i = left; i <= right; i++) {
            tempArray[i] = items.get(i);
        }
        int i = left;
        int j = middle + 1;
        int k = left;
        while (i <= middle && j <= right) {
            if (tempArray[i].compareTo(tempArray[j])==-1) {
                items.set(k, tempArray[i]);
                i++;
            } else {
                items.set(k, tempArray[j]);
                j++;
            }
            k++;
        }
        while (i <= middle) {
            items.set(k, tempArray[i]) ;
            k++;
            i++;
        }
    }

}
