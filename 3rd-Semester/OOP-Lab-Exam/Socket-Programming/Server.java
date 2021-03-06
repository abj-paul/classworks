import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
	private ServerSocket serverSocket = null;
	private Socket socket = null;
	private DataInputStream socket_input_stream = null;
	private DataOutputStream socket_output_stream = null;
	
	Server(int port){
		try {
		serverSocket = new ServerSocket(port);
		System.out.println("Server is waiting for connections.");
		socket = serverSocket.accept();
		System.out.println("Connection established!");
		
		this.socket_input_stream = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
		this.socket_output_stream = new DataOutputStream(socket.getOutputStream());
		
		String line = "Server has been connected!";
		while(!line.equals("Over")) {
			line = this.socket_input_stream.readUTF();
			System.out.println("Client: "+line);
			this.socket_output_stream.writeUTF("Server: "+line);
		}
		
		this.socket.close();
		this.socket_input_stream.close();
		this.socket_output_stream.close();
		
		}catch(IOException e) {e.printStackTrace();}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Server server = new Server(30001);

	}

}
