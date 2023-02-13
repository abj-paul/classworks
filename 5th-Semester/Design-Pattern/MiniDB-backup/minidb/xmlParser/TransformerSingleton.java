import javax.xml.transform.*;

public class TransformerSingleton {
    private static Transformer transformer = null;

    private TransformerSingleton() {
	transformer = TransformerFactory.newInstance().newTransformer();
	transformer.setOutputProperty(OutputKeys.ENCODING, "UTF-8");
	transformer.setOutputProperty(OutputKeys.INDENT, "no");
	transformer.setOutputProperty(OutputKeys.METHOD, "xml");
    }

    public static Transformer getTransformer(){
	if(transformer==null)
	    new TransformerSingleton();
	return transformer;
    }
}
