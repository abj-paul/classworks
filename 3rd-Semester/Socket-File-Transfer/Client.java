import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    private String filename = "input.txt";
    private Socket socket;
    private DataOutputStream dataOutputStream;
    private DataInputStream dataInputStream;
    private InputStream fileInputStream;

    private String ipAddress;
    private int port;

    public Client(String ipAddress, int port){
        this.ipAddress = ipAddress;
        this.port = port;
    }

    public void startConnection(){
        try {
            this.socket = new Socket(this.ipAddress, this.port);

            this.dataInputStream = new DataInputStream(new BufferedInputStream(this.socket.getInputStream()));
            this.dataOutputStream = new DataOutputStream(this.socket.getOutputStream());
            this.fileInputStream = new FileInputStream(this.filename);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        System.out.println("Established Connection.");
    }

    public void sendData(){
        String line = "";
        Scanner scannar = new Scanner(this.fileInputStream);
        while(!line.equals("Over")){
            try {
                line = scannar.nextLine();
                this.dataOutputStream.writeUTF(line);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        scannar.close();
    }

    public void closeConnection(){
        try {
            this.socket.close();
            this.dataInputStream.close();
            this.dataOutputStream.close();
            this.fileInputStream.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        System.out.println("Connection closed,");
    }

    public static void main(String[] args) {
        Client client = new Client("127.0.0.1",20234);
        client.startConnection();
        client.sendData();
        client.closeConnection();
    }
}
