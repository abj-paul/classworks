package minidb.xmlParser;

import java.io.File;
import java.io.IOException;
import javax.xml.parsers.*;
import javax.xml.transform.*;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import org.w3c.dom.*;
import org.xml.sax.SAXException;


public abstract class XMLFiles {
    protected File xmlFile;
    protected Document doc;

    private void createNewFile(String path) throws IOException, SAXException, ParserConfigurationException{
	this.xmlFile = Factory.createFileObject(path);
	boolean NoFileFound = xmlFile.createNewFile();
	load(NoFileFound);
    }

    public XMLFiles(String path) {
        try {
		Factory.createDirectoryForPath(path);
	    	createNewFile(path);
	    	
                    
	} catch (ParserConfigurationException | SAXException | IOException err) {
            System.out.println(err);
            err.printStackTrace();
        }
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


    private void transformDOMToStream(Transformer transformer) throws TransformerException{
            DOMSource source = new DOMSource(this.doc);
            StreamResult result = new StreamResult(this.xmlFile);
            transformer.transform(source, result);
    }
    protected void updateFile() {
        try {
	    Transformer transformer = TransformerSingleton.getTransformer();
	    transformDOMToStream(transformer);
            print("Updated;");

        } catch (TransformerException err) {
            err.printStackTrace();
        }
    }

    protected void print(String x) {
        System.out.println(x);
    }
}
