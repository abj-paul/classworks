package first.socket;
import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client {
	private Socket socket;
	private DataInputStream input_stream_from_server;
	private DataOutputStream output_stream_to_server;
	private DataInputStream input_stream_from_console;
	
	Client(String ip, int port){
		try{
			socket = new Socket(ip, port);
			input_stream_from_server = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
			output_stream_to_server = new DataOutputStream(socket.getOutputStream());
			input_stream_from_console = new DataInputStream(new BufferedInputStream(System.in));
			
			String line = "";
			while(!line.equals("Over")) {
				line = input_stream_from_console.readUTF();
				output_stream_to_server.writeUTF(line);
				System.out.println(input_stream_from_server.readUTF());
			}
			input_stream_from_server.close();
			output_stream_to_server.close();
			input_stream_from_console.close();
			socket.close();
			
		}catch(UnknownHostException e) {e.printStackTrace();}
		catch(IOException e) {e.printStackTrace();} 
	}
	
	public static void main(String[] args) {
		Client client = new Client("127.0.0.1",50012);
	}
}
