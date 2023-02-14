import java.util.ArrayList;
import java.nio.file.FileSystems;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardWatchEventKinds;
import java.nio.file.WatchEvent;
import java.nio.file.WatchKey;
import java.nio.file.WatchService;
import java.text.SimpleDateFormat;
import java.util.Calendar;
//ENTRY_CREATE, ENTRY_DELETE, and ENTRY_MODIFY 


abstract class Subject {
    private ArrayList<Observer> observers = new ArrayList<Observer>();
    
    public void Attach(Observer observer){
	this.observers.add(observer);
    }
    public void Detach(Observer observer){
	this.observers.remove(observer);
    }	
    public void Notify(){
	for(Observer observer: observers) 
	    observer.update(this);
    }
    
    public abstract void stateChange();
}

class FileMonitor extends Subject {
    private String pathStr = ".";
    private String fileName = "testfile";
    private String timeStamp = null;

	
    @Override
    public void stateChange(){
	Path path= Paths.get(pathStr);
	System.out.println(path);
	try (final WatchService watchService = FileSystems.getDefault().newWatchService()) {
	    final WatchKey watchKey = path.register(watchService, StandardWatchEventKinds.ENTRY_MODIFY);
	    while (true) {
		final WatchKey wk = watchService.take();
		for (WatchEvent<?> event : wk.pollEvents()) {
		    final Path changed = (Path) event.context();
		    System.out.println(changed);

		    if (changed.endsWith(fileName)) {
			this.timeStamp = new SimpleDateFormat("yyyyMMdd_HHmmss").format(Calendar.getInstance().getTime());
			System.out.println(fileName+" has changed!Time to notify observers~");
			Notify();
		    }
		}
		// reset the key
		boolean valid = wk.reset();
		if (!valid) {
		    System.out.println("Key has been unregisterede");
		}
	    }
	} catch(Exception err){
	    err.printStackTrace();
	}   
    }

    public String getFileName(){
	return this.fileName;
    }
    public String getTimeStamp(){
	return this.timeStamp;
    }
}















interface Observer {
	void update(Subject subject);
}

class FileMonitorLocalGUI implements Observer {
	private FileMonitor subject;

	public FileMonitorLocalGUI(Subject subject){
	    this.subject = (FileMonitor)subject;
	    subject.Attach(this);
	}
    
	public void update(Subject newSubject){ // Is it valid?
	    this.subject = (FileMonitor)newSubject;
		System.out.println("Notification has been received locally!");
		System.out.println(this.subject.getFileName());
		System.out.println(this.subject.getTimeStamp());
	}
	public void draw() {
	    System.out.println("Done drawing the GUI!");
	}

}

class FileMonitorCloudGUI implements Observer {
	private FileMonitor subject;

	public FileMonitorCloudGUI(Subject subject){
	    this.subject = (FileMonitor)subject;
	    subject.Attach(this);
	}

	@Override
	public void update(Subject newSubject){ // Is it valid?
	    this.subject = (FileMonitor)newSubject;
		System.out.println("Notification has been received in cloud!");
		System.out.println(this.subject.getFileName());
		System.out.println(this.subject.getTimeStamp());
	}

	public void draw() {
	    System.out.println("Done drawing the GUI!");
	}
}


public class Client {
	public static void main(String[] args){
		Subject monitor = new FileMonitor();

		FileMonitorLocalGUI localGUI = new FileMonitorLocalGUI(monitor);	
		FileMonitorCloudGUI cloudGUI = new FileMonitorCloudGUI(monitor);


		FileMonitorLocalGUI localGUI2 = new FileMonitorLocalGUI(monitor);	
		FileMonitorLocalGUI localGUI3 = new FileMonitorLocalGUI(monitor);	
		FileMonitorLocalGUI localGUI4 = new FileMonitorLocalGUI(monitor);	
		FileMonitorLocalGUI localGUI5 = new FileMonitorLocalGUI(monitor);	
		FileMonitorLocalGUI localGUI6 = new FileMonitorLocalGUI(monitor);	
		FileMonitorLocalGUI localGUI7 = new FileMonitorLocalGUI(monitor);	
		FileMonitorLocalGUI localGUI8 = new FileMonitorLocalGUI(monitor);	

		monitor.stateChange();

		localGUI2.draw();
		localGUI3.draw();
		localGUI4.draw();
		localGUI5.draw();
		localGUI6.draw();
		localGUI7.draw();
		localGUI8.draw();
	}
}


