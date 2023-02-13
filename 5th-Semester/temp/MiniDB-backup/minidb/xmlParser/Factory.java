
package minidb.xmlParser;
import java.io.File;
import constants.constants;

public class Factory {
        public static void createDirectoryForPath(String path){
            new File(constants.DB_DIR_PATH).mkdir(); // create `db` directory if it doesn't exist
        }
        
        public static File createFileObject(String dbPath){
            File f = new File(dbPath);
	    return f;
        }
}

abstract class XMLFactory{

}
class RegistryFileFactory extends XMLFactory{
	public RegistryFile createRegistryFile(String path){
		RegistryFile registryFile = new RegistryFile(path);
		return registryFile;
	}	
}

class DatabaseFileFactory extends XMLFactory{
	public DatabaseFile createDatabaseFile(String path){
		DatabaseFile databaseFile = new DatabaseFile(path);
		return databaseFile;
	}
}
