package patterns;

public class OrderNotFoundException extends Exception {
    OrderNotFoundException(String msg){
        super(msg);
    }
}
