import java.util.ArrayList;

interface PrintMode {
	boolean useModality();
	double getCostPerPage();
}

class DefaultConstant {
    public static int HIGH=3, MEDIUM=2, LOW=1;
    public static double COST_PER_PAGE = 0.54;
}

class TonerSaveMode implements PrintMode {
    private int tonerSavingLevel;
    private double colorIntensity;
    private double costPerPage;
    
    public TonerSaveMode(int tonerSavingLevel, double colorIntensity) {
	this.tonerSavingLevel = tonerSavingLevel;
	this.colorIntensity = colorIntensity;
	this.costPerPage = DefaultConstant.COST_PER_PAGE;
    }

    void saveToner(){ //DOUBT
	if(tonerSavingLevel==DefaultConstant.HIGH) reduceColorIntensityStandardAlgorithm();
	else if(tonerSavingLevel==DefaultConstant.MEDIUM) reduceColorIntnsityAlgorithmOne();
	else if(tonerSavingLevel==DefaultConstant.LOW) reduceColorIntnsityAlgorithmTwo();
    }
    void reduceColorIntensityStandardAlgorithm() {
	this.colorIntensity -= 19;
	this.costPerPage -= colorIntensity / 100;
	System.out.println("Standard Algorithm to reduce color intensity.");
    }
    void reduceColorIntnsityAlgorithmOne() {
	this.colorIntensity -= 16;
	this.costPerPage -= colorIntensity / 100;
	System.out.println("Standard Algorithm to reduce color intensity.");
    }
    void reduceColorIntnsityAlgorithmTwo() {
	this.colorIntensity -= 24;
	this.costPerPage -= colorIntensity / 100;
	System.out.println("Standard Algorithm to reduce color intensity.");
    }

    @Override
    public boolean useModality() {
	this.saveToner();
	return true;
    }
    @Override
    public double getCostPerPage() {
	return this.costPerPage;
    }
    
}

class PageSaveMode implements PrintMode {
    double numberOfPages;
    int pageSize;
    double costPerPage;
    String orientation;
    void renderPreview(){
	//shows a preview of updated document (perhaps updated by the above algorithm.)
    }
	
    PageSaveMode(double numberOfPages, int pageSize, String orientation) {
	this.numberOfPages = numberOfPages;
	this.pageSize = pageSize;
	this.orientation = orientation;
	this.costPerPage = DefaultConstant.COST_PER_PAGE;
    }

    private void savePage() {
	// Adjust page size & Orientation to reduce the number of pages required.
	this.pageSize -= 10;
	this.numberOfPages = this.numberOfPages * 0.9;
	this.costPerPage -= numberOfPages / 100;
	System.out.println("Save number of pages required!");
    }
    @Override
    public boolean useModality() {
	this.savePage();
	return true;
    }
    @Override
    public double getCostPerPage() {
	return this.costPerPage;
    }

}

class BoosterSaveMode implements PrintMode {
    double intensityThreshold;
    double costPerPage;
    double colorIntensity;

    BoosterSaveMode(double intensityThreshold, double colorIntensity) {
	this.intensityThreshold = intensityThreshold;
	this.colorIntensity = colorIntensity;
	this.costPerPage = DefaultConstant.COST_PER_PAGE;
    }

    private void boost(){ //increaseColorIntensityAlgorithm
	//increases color intensity up to a maximum acceptable level that is set via its intensityThreshold field.
	this.colorIntensity = this.intensityThreshold;
	this.costPerPage += this.colorIntensity / 10;
	System.out.println("Boost printing!");
    }
    @Override
    public boolean useModality() {
	this.boost();
	return true;
    }
    @Override
    public double getCostPerPage() {
	return this.costPerPage;
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
	int lastIndex = printRequests.size() - 1;
	return this.printRequests.remove(lastIndex);
    }
    public void pushJob(PrintRequest printRequest){
	this.printRequests.add(printRequest);
    }

    void changePriority(){
	System.out.println("Change priority of a job.");
    }
}

class PrintRequest {
    Document document;
    PrintMode mode;
    public PrintRequest(Document document, PrintMode mode) {
	this.document = document;
	this.mode = mode;
    }
    
}

class Document {
    int pageSize;
    double numberOfPages;
    String orientation;
    public int getPageSize() {
	return pageSize;
    }
    public double getNumberOfPages() {
	return numberOfPages;
    }
    public String getOrientation() {
	return orientation;
    }
    
}

class PrioritySetting {
}


public class Solution {
    public static void main(String[] args) {
	PrioritySetting prioritySetting = new PrioritySetting();
	PrintJob printJob = new PrintJob(prioritySetting);
	
	Document document = new Document();
	PrintMode mode = new PageSaveMode(document.getNumberOfPages(), document.getPageSize(), document.getOrientation());
	PrintRequest printRequest = new PrintRequest(document, mode);
	
	printJob.pushJob(printRequest);
    }
}
