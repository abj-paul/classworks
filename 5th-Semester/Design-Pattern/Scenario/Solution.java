import java.util.ArrayList;

interface PrintMode {
	boolean useModality();

	double getCostPerPage();
}

interface TonerSavingAlgorithm {
	void reduceColorIntensity();
}

class StandardAlgorithm implements TonerSavingAlgorithm {
	TonerSaveMode mode;

	public StandardAlgorithm(TonerSaveMode mode) {
		this.mode = mode;
	}

	@Override
	public void reduceColorIntensity() {
		mode.setColorIntensity(1.9);
		mode.setCostPerPage(mode.getColorIntensity() / 100);
		System.out.println("Standard Algorithm to reduce color intensity.");
	}
}

class AlgorithmOne implements TonerSavingAlgorithm {
	TonerSaveMode mode;

	public AlgorithmOne(TonerSaveMode mode) {
		this.mode = mode;
	}

	@Override
	public void reduceColorIntensity() {
		mode.setColorIntensity(1.6);
		mode.setCostPerPage(mode.getColorIntensity() / 100);
		System.out.println("Algorithm One to reduce color intensity.");
	}
}

class AlgorithmTwo implements TonerSavingAlgorithm {
	TonerSaveMode mode;

	public AlgorithmTwo(TonerSaveMode mode) {
		this.mode = mode;
	}

	@Override
	public void reduceColorIntensity() {
	    mode.setColorIntensity(2.4);
	    mode.setCostPerPage(mode.getColorIntensity() / 100);
	    System.out.println("Algorithm Two to reduce color intensity.");
	}
}



class DefaultConstant {
    public static int HIGH=3, MEDIUM=2, LOW=1;
    public static double COST_PER_PAGE = 0.54;
    public static int PAGE_SIZE = 231;
    public static int DESCENDING = 100;
}

class TonerSaveMode implements PrintMode {
    private double colorIntensity;
    private double costPerPage;
    TonerSavingAlgorithm tonerSavingAlgorithm;

	public void setColorIntensity(double colorIntensity) {
	    this.colorIntensity = colorIntensity;
	}

	public double getColorIntensity() {
	    return this.colorIntensity;
	}

	public void setCostPerPage(double costPerPage) {
		this.costPerPage = costPerPage;
	}
    
    public TonerSaveMode(double colorIntensity) {
	this.colorIntensity = colorIntensity;
	this.costPerPage = DefaultConstant.COST_PER_PAGE;
    }

    public void setAlgorithm(TonerSavingAlgorithm tonerSavingAlgorithm)  {
	this.tonerSavingAlgorithm = tonerSavingAlgorithm;
    }

    void saveToner(){
	this.tonerSavingAlgorithm.reduceColorIntensity();
    }


    @Override
    public boolean useModality() { // Conflict between naming methods with their action and interface.
	this.saveToner();
	return true;
    }
    @Override
    public double getCostPerPage() {
	return this.costPerPage;
    }
    
}

class PageSaveMode implements PrintMode {
    private double numberOfPages;
    private double pageSize;
    private String orientation;
    private double costPerPage;
    void renderPreview(){
	System.out.println("Showing doc preview.");
    }
	
    PageSaveMode(Document document) {
	this.numberOfPages = document.getNumberOfPages();
	this.pageSize = document.getPageSize();
	this.orientation = document.getOrientation();
	this.costPerPage = DefaultConstant.COST_PER_PAGE;
    }

    private void reduceNumberOfPages() {
	adjustPageSize();
	adjustOrientation();
	this.numberOfPages = this.numberOfPages * 0.9;
	estimatePerPageCost();
    }
    
    private void adjustPageSize() {
	this.pageSize -= 10;
    }

    private void estimatePerPageCost(){
	this.costPerPage -= numberOfPages / 100;
    }

    private void adjustOrientation() {
	if (orientation == "LEFT")
	    this.costPerPage += pageSize / 100;
	else orientation = "CENTER";
    }
    @Override
    public boolean useModality() {
	this.reduceNumberOfPages();
	return true;
    }
    @Override
    public double getCostPerPage() {
	return this.costPerPage;
    }

}

class BoosterSaveMode implements PrintMode {
    private double intensityThreshold; // Primite obsession
    private double costPerPage;
    private double colorIntensity;

    BoosterSaveMode(double intensityThreshold, double colorIntensity) {
	this.intensityThreshold = intensityThreshold;
	this.colorIntensity = colorIntensity;
	this.costPerPage = DefaultConstant.COST_PER_PAGE;
    }

    private void boost(){ 
	increaseColorIntensityToMaximum();
	this.costPerPage += this.colorIntensity / 10;
    }

    private void increaseColorIntensityToMaximum() {
	this.colorIntensity = this.intensityThreshold;
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
    private ArrayList<PrintRequest> printRequests;
    private PrioritySetting prioritySetting;

    PrintJob(PrioritySetting prioritySetting) {
	this.prioritySetting = prioritySetting;
	this.printRequests = new ArrayList<PrintRequest>();
    }

    public PrintRequest pullJob(){
	int lastIndex = printRequests.size() - 1;
	if (prioritySetting.order() == DefaultConstant.DESCENDING) // Replace with polymorphism
	    lastIndex = 0;
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
    private Document document;
    private PrintMode mode;
    public PrintRequest(Document document, PrintMode mode) {
	this.document = document;
	this.mode = mode;
    }
    public Document getDocument() {
	return document;
    }
    
    void handleModality(){
	this.mode.useModality();
	this.preprocess();
	System.out.println("Cost to print: "+mode.getCostPerPage());
    }

    private void preprocess(){
	System.out.println("Preproccessing print request.");
    }
}

class Document {
    String documentContent;
   
    Document(String documentContent) {
	this.documentContent = documentContent;
    }
    
    public int getPageSize() {
	return this.extractPageSize();
    }
    public double getNumberOfPages() {
	return this.extractPageCount();
    }
    public String getOrientation() {
	return this.extractOrientation();
    }

    private int extractPageSize() {
	return documentContent.length();
    }

    private double extractPageCount() {
	return documentContent.length() / DefaultConstant.PAGE_SIZE;
    }

    private String extractOrientation() {
	return "RIGHT"; // Constant smell
    }

	public double getColorIntensity() {
	    return 12.3;
	}
    
}

class PrioritySetting { // Lazy class
    int order() {
	return DefaultConstant.DESCENDING;
    }
}


public class Solution {
    public static void main(String[] args) {
	PrioritySetting prioritySetting = new PrioritySetting();
	PrintJob printJob = new PrintJob(prioritySetting);
	
	Document document = new Document("Test Document Contents.");
	PrintMode mode = new PageSaveMode(document);
	PrintRequest printRequest = new PrintRequest(document, mode);
	
	printJob.pushJob(printRequest);


	document = new Document("Test Document Contents.");
	TonerSaveMode mode1 = new TonerSaveMode(document.getColorIntensity());
	TonerSavingAlgorithm tonerSavingAlgorithm = new StandardAlgorithm(mode1);
	mode1.setAlgorithm(tonerSavingAlgorithm);
	printRequest = new PrintRequest(document, mode1);

	printJob.pushJob(printRequest);
    }
}
