import java.util.Random;
import java.lang.Runnable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

class SimpleArray {
    private final int array[];
    private int writeIndex=0;
    private final static Random generator = new Random();

    public SimpleArray(int size){
        array = new int[size];
    }

    public void add(int value){
        int position = writeIndex;
        try{
            Thread.sleep(generator.nextInt(500));
        }catch(InterruptedException exception){
            exception.printStackTrace();
        }
        array[position]=value;
        System.out.printf("%s wrote %2d to element %d.\n", Thread.currentThread().getName(), value, position);

        ++writeIndex;
        System.out.printf("Next write index:%d\n",writeIndex);
    }

    public String toString(){
        String arrayString = "\nContents of SimpleArray:\n";
        for(int i=0; i<array.length; i++) arrayString+=array[i]+" ";

        return arrayString;
    }
}

class ArrayWriter implements Runnable{
    private final SimpleArray sharedSimpleArray;
    private final int startValue;

    public ArrayWriter(int value, SimpleArray array){
        startValue=value;
        sharedSimpleArray=array;
    }
    public void run(){
        for(int i=startValue; i<startValue+3; i++) sharedSimpleArray.add(i);
    }
}

public class SharedArrayTest{
    public static void main(String[] args){
        SimpleArray sharedSimpleArray = new SimpleArray(6);

        ArrayWriter writer1 = new ArrayWriter(1, sharedSimpleArray);
        ArrayWriter writer2 = new ArrayWriter(11, sharedSimpleArray);

        ExecutorService executor = Executors.newCachedThreadPool();

        executor.execute(writer1);
        executor.execute(writer2);

        executor.shutdown();
        try{
            boolean tasksEnded = executor.awaitTermination(1, TimeUnit.MINUTES);
            if(tasksEnded) System.out.println(sharedSimpleArray);
            else System.out.println("Timed out while waiting for tasks to finish");
        }catch(InterruptedException exception){
            System.out.println("Interrupted while waiting for tasks to finish.");
        }
    }
}