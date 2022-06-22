package socket;
import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class Client {
	private Socket socket = null;
	private DataInputStream socket_input_stream = null;
	private DataInputStream console_input_stream = null;
	private DataOutputStream socket_output_stream = null;
	
	Client(String ip_addr, int port){
		try {
			this.socket = new Socket(ip_addr, port);
			this.socket_input_stream = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
			this.socket_output_stream = new DataOutputStream(socket.getOutputStream());
			this.console_input_stream = new DataInputStream(System.in);
			
			String line = "";
			while(!line.equals("Over")) {
				this.socket_input_stream.readUTF();
				line = this.console_input_stream.readLine();
				this.socket_output_stream.writeUTF(line);
			}
			
			this.socket.close();
			this.socket_input_stream.close();
			this.socket_output_stream.close();
			this.console_input_stream.close();
			
		}catch(IOException e) {e.printStackTrace();}
	}
	
	public static void main(String[] args) {
		Client client = new Client("127.0.0.1", 42312);
	}
}
