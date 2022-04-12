package collection.framework;

import java.net.Socket;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		try {
		// TODO Auto-generated method stub
		ArrayList al = new ArrayList();
		al.add("aaa");
		al.add(2);
		al.add(new Object());
		al.add(new Socket("127.0.0.1",5421));
		}catch(Exception e) {e.printStackTrace();}
	}

}
