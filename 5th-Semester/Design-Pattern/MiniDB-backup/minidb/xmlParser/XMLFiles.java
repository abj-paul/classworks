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
