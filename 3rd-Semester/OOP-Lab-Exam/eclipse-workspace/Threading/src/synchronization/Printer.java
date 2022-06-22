package synchronization;

public class Printer{
	int printer_id;
	Printer(int printer_id){
		this.printer_id=printer_id;
	}
	synchronized void printFile(String filename, int number_of_copies) {
		for(int i=0; i<number_of_copies; i++) {
			System.out.println(">> Printing "+i+"th copy of "+filename + "with Printer "+this.printer_id);
			try {
			Thread.sleep(500);
			}catch(InterruptedException e) {e.printStackTrace();}
		}
	}
}
