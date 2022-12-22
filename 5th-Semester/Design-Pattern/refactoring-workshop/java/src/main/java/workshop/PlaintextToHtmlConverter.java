package workshop;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;


public class PlaintextToHtmlConverter {
    String INPUT_FILE = "sample.txt";
    String sourceString;
    int iterator;
    List<String> totalEncodedOutputList;
    List<String> encodedLineList;
    String characterToEncode;

    public String toHtml() throws Exception {
        String text = read();
	return basicHtmlEncode(text);
    }
    protected String read() throws IOException {
	Path filePath = Paths.get(INPUT_FILE);
        return new String(Files.readAllBytes(filePath));
    }

    private String basicHtmlEncode(String sourceString){
	initializeClassFields(sourceString);
        
        while (endNotReached()){
	    encodeCharAtIndex(iterator);
            if (endReached()) break;

            characterToEncode = pickCharacterFromSourceString();
        }
        ConvertEncodedLineListToString();

        String finalResult = stringify(totalEncodedOutputList);
        return finalResult;
    }
    private void initializeClassFields(String sourceString){
	this.sourceString = sourceString;
        iterator = 0;
        totalEncodedOutputList = new ArrayList<>();
        encodedLineList = new ArrayList<>();
        characterToEncode = pickCharacterFromSourceString();
    }
    private boolean endNotReached(){
	return iterator <= this.sourceString.length();
    }
    private boolean endReached(){
	return iterator >= sourceString.length();
    }

    private String stringify(List<String> list){
	return String.join("<br />", totalEncodedOutputList);
    }

    private String pickCharacterFromSourceString(){
        char c = sourceString.charAt(iterator);
        iterator += 1;
        return String.valueOf(c);
    }

    private void ConvertEncodedLineListToString(){
        String line = String.join("", encodedLineList);
        totalEncodedOutputList.add(line);
        encodedLineList = new ArrayList<>();
    }

    private void pushACharacterToTheOutput() {
        encodedLineList.add(characterToEncode);
    }

    private void encodeCharAtIndex(int index){
	switch (characterToEncode){
	case "<":
	    encodedLineList.add("&lt;");
	    break;
	case ">":
	    encodedLineList.add("&gt;");
	    break;
	case "&":
	    encodedLineList.add("&amp;");
                    break;
	case "\n":
	    stringify(totalEncodedOutputList);
	    break;
	default:
	    pushACharacterToTheOutput();
	}
    }
}
