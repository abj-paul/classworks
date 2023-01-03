import java.util.ArrayList;


abstract class PrintMode { // Refused Bequest
    int numberOfPages;
    int pageSize;
    String orientation;
    String colorIntensity;
    int costPerPage;

    abstract void saveToner();
    abstract void savePage();
    abstract void boost();
}

class TonerSaveMode extends PrintMode { 
    int tonerSavingLevel;
    int HIGH, MEDIUM, LOW;

    public TonerSaveMode(String colorIntensity, int tonerSavingLvel) {
        this.colorIntensity = colorIntensity;
        this.tonerSavingLevel = tonerSavingLvel;
    }
    @Override
    void saveToner(){ //Duplicate Code, Switch case smell
	if(tonerSavingLevel==HIGH) reduceColorIntensityStandardAlgorithm();
	else if(tonerSavingLevel==MEDIUM) reduceColorIntnsityAlgorithmOne();
	else if(tonerSavingLevel==LOW) reduceColorIntnsityAlgorithmTwo();
    }
    @Override
    void savePage() {
	System.out.println("Save the page!");
    }
    @Override
    void boost() {
	System.out.println("Boost printing!");
    }

    void reduceColorIntensityStandardAlgorithm() {
	System.out.println("Standard Algorithm to reduce color intensity.");
    }
    void reduceColorIntnsityAlgorithmOne() {
	System.out.println("Standard Algorithm to reduce color intensity.");
    }
    void reduceColorIntnsityAlgorithmTwo() {
	System.out.println("Standard Algorithm to reduce color intensity.");
    }

    
}

class PageSaveMode extends PrintMode {

    PageSaveMode(int numberOfPages, int pageSize, String orientation, int costPerPage) { // Long Parameter List
        this.numberOfPages = numberOfPages;
        this.pageSize = pageSize;
        this.orientation = orientation;
        this.costPerPage = costPerPage;
        }
    void renderPreview(){
        System.out.println("shows a preview of updated document (perhaps updated by the above algorithm.");
    }
    @Override
    void saveToner(){ 
    }
    @Override
    void savePage() {
	System.out.println("Adjust page size & Orientation to reduce the number of pages required.");
    }
    @Override
    void boost() {
	System.out.println("Boost printing!");
    }
}

class BoosterSaveMode extends PrintMode {
    int intensityThreshold;

    BoosterSaveMode(int intensityThreshold, String colorIntensity) {
        this.intensityThreshold = intensityThreshold;
        this.colorIntensity = colorIntensity;
     }
    @Override
    void saveToner(){ 
    }
    @Override
    void savePage() {
	System.out.println("Adjust page size & Orientation to reduce the number of pages required.");
    }
    @Override
    void boost() { 
	System.out.println("Boost printing!");
    }
}

class PrintJob {
    ArrayList<PrintRequest> printRequests;
    PrioritySetting prioritySetting;

    PrintJob(PrioritySetting prioritySetting) {
	this.prioritySetting = prioritySetting;
	this.printRequests = new ArrayList<PrintRequest>();
    }

    public PrintRequest pullJob(){ 
	int lastIndex = printRequests.size() - 1; // Primitive Obsession
	return this.printRequests.remove(lastIndex);
    }
    public void pushJob(PrintRequest printRequest){
	this.printRequests.add(printRequest);
    }

    void changePriority(){
		this.prioritySetting.doSomeMoreStuffsIdkAbout();
		System.out.println("Change priority of a job.");
    }
}

class PrintRequest { // Lazy Class
    Document document;
    PrintMode mode;
    public PrintRequest(Document document, PrintMode mode) {
	this.document = document;
	this.mode = mode;
    }
    
}
class Document {}

class PrioritySetting { // Feature Envy
    private int priorityOrder;

    public int order() {
	return this.priorityOrder;
    }
    void doSomeMoreStuffsIdkAbout(){
	priorityOrder = DefaultConstant.DESCENDING;
    }
}


public class Problem {
    public static void main(String[] args) {
	PrioritySetting prioritySetting = new PrioritySetting();
	PrintJob printJob = new PrintJob(prioritySetting);
	
	Document document = new Document();
	PrintMode mode = new PageSaveMode(0, 0, null, 0);
	PrintRequest printRequest = new PrintRequest(document, mode);
	
	printJob.pushJob(printRequest);
    }
}
