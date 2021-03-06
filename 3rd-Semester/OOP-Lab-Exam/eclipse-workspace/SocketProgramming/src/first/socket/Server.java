package first.socket;

import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
	private ServerSocket serverSocket;
	private Socket socket;
	private DataInputStream input_stream;
	private DataOutputStream output_stream;
	
	Server(int port){
		try {
			this.serverSocket = new ServerSocket(port);
			socket = serverSocket.accept();
			System.out.println("Connection Established!");
			
			input_stream = new DataInputStream( new BufferedInputStream(socket.getInputStream()) );
			output_stream = new DataOutputStream(socket.getOutputStream());
			
			String line = "";
			while(!line.equals("Over")) {
				line = input_stream.readUTF();
				System.out.printf("Client has sent: "+line);
				output_stream.writeUTF("Server has sent:"+line);
			}
			serverSocket.close();
			socket.close();
			input_stream.close();
			output_stream.close();
					
		}catch(IOException e) {e.printStackTrace();}
		
	}
	public static void main(String[] args) {
		Server server = new Server(50012);
	}
}
