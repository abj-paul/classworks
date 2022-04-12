package executor.service;

public class Tasks implements Runnable{
	Printer pRef;
	Tasks(Printer printer){
		pRef = printer;
	}
	@Override
	public void run() {
		pRef.printFile("Sherlock Holmes.pdf", 5);
	}
}
