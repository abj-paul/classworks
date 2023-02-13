
public class XMLFileAbstractFactory {
    private void createNewFile(String path) throws IOException, SAXException, ParserConfigurationException{
	this.xmlFile = Factory.createFileObject(path);
	boolean NoFileFound = xmlFile.createNewFile();
	load(NoFileFound);
    }
    
    
    
    private void load(boolean NoFile) throws ParserConfigurationException, SAXException, IOException {
        DocumentBuilderFactory docFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder docBuilder = docFactory.newDocumentBuilder();
        if (NoFile) {
            doc = docBuilder.newDocument();
            createFile(); 
        } else {
            doc = docBuilder.parse(xmlFile);
        }
    }
    
    abstract void createFile();
    
    /**
     * Call this method to update the XML file.
     */
}
