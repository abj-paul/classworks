public class Ram extends Composite implements IVersion {
    private String version;

    Ram(String nameOfEquip) {
        super(nameOfEquip);
    }
    
    public void setVersion(String version){
        this.version = version;
    }
    public String getVersion(){
        return this.version;
    }

}
