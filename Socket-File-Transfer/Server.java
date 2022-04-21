import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    private ServerSocket serverSocket;
    private DataInputStream dataInputStream;
    private DataOutputStream dataOutputStream;
    private Socket socket;

    private int port;

    public Server(int port){
        this.port = port;
    }
    public void start(){
        try {
            this.serverSocket = new ServerSocket(this.port);
            System.out.println("Server has started. Waiting for connection..");
            this.socket = serverSocket.accept();
            this.dataInputStream = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
            this.dataOutputStream = new DataOutputStream(socket.getOutputStream());
            System.out.println("Connection established!");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void receiveData(){
        String line = "";
        while(!line.equals("Over")){
            System.out.println("Client:"+line);
            try {
                line = this.dataInputStream.readUTF();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        // Close connection
    }
    public void closeConnection(){
        try {
            this.socket.close();
            this.dataOutputStream.close();
            this.dataInputStream.close();
            this.serverSocket.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        System.out.println("Connection has been closed.");
    }

    public static void main(String[] args) {
        Server server = new Server(20234);
        server.start();
        server.receiveData();
        server.closeConnection();
    }
}
