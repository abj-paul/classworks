import java.util.Random;

class PrintTask implements Runnable{
    private final int sleepTime;
    private final String taskName;
    private final static Random generator = new Random();

    public PrintTask(String name){
        this.taskName = name;
        this.sleepTime = generator.nextInt(5000);
    }

    public void run(){
        try{
            System.out.printf("%s going to sleep for %d milliseconds.\n", taskName, sleepTime);
            Thread.sleep(sleepTime);
        }catch(InterruptedException exception){
            System.out.printf("%s terminated prematurely due to interruption.\n",taskName);
        }
        System.out.printf("%s done sleeping.\n",this.taskName);
    }
}

public class ThreadCreator{
    public static void main(String[] args){
        Thread thread1 = new Thread(new PrintTask("Task1"));
        Thread thread2 = new Thread(new PrintTask("Task2"));
        Thread thread3 = new Thread(new PrintTask("Task3"));

        // CONTROL GOES TO CPU.
        thread1.start();
        thread2.start();
        thread3.start();

        System.out.println("Tasks started, main ends!!!\n");
    }
}
