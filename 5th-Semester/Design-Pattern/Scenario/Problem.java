abstract class PrintMode {
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

    @Override
    void saveToner(){ //DOUBT
	if(tonerSavingLevel==HIGH) reduceColorIntensityAlgorithm();
	else if(tonserSavingLevel==MEDIUM) reduceColorIntnsityAlgorithm();
	else if(tonserSavingLevel==LOW) reduceColorIntnsityAlgorithm();
    }
}

class PageSaveMode extends PageSaveMode {
    void reduceNumberOfPagesAlgorithm(){
	// Adjust page size & Orientation to reduce the number of pages required.
    }

    void renderPreview(){
	//shows a preview of updated document (perhaps updated by the above algorithm.)
    }
}

class BoosterSaveMode extends PrintMode {
    int intensityThreshold;
    void increaseColorIntensityAlgorithm(){
	//increases color intensity up to a maximum acceptable level that is set via its intensityThreshold field.
    }
}

class PrintJob {
    ArrayList<PrintRequest> printRequests;
    PrioritySetting prioritySetting;

    void pullJob(){

    }

    void changePriority(){

    }
}

class PrintRequest {
    Document document;
    PrintMode mode;
}
class Document {}
class PrioritySetting {}
