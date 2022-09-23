#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h> // Unix Standard Files. Linux based posix & ip adresss, POSIX

#include<netinet/in.h> //for strucutre inet_addr
#include<sys/types.h> // for structure sockaddr_in
#include<sys/stat.h> // for umask 
#include<sys/socket.h>
#include <arpa/inet.h> //for inet_htop


#define BACKLOG 15
#define MAX_TRANSFER_DATA_SIZE 256 

void show_error_message_and_exit(const char* msg);
void server(int port, FILE* fptr);
char* get_ip_from_address(struct sockaddr_in* addr);


int main(int argc, char* argv[]){
	if(argc != 2) 
		show_error_message_and_exit("Not enough paremeter! Server needs port number to run!");

	int port = atoi(argv[1]);	
	int pid = fork();


	 if (pid < 0) {
             exit(EXIT_FAILURE);
	 } else if (pid > 0) {
             exit(EXIT_SUCCESS);
	 }

 	umask(0);

        int sid = setsid();
    	if (sid < 0) {
        	exit(EXIT_FAILURE);
	}

	if ((chdir("/home/abhijit/")) < 0) {
	    exit(EXIT_FAILURE);
	}
  
	FILE* fptr = fopen("chat_record.txt","w");
	if(fptr==NULL) show_error_message_and_exit("Error opening file.");

   
    server(port, fptr);
    exit(EXIT_SUCCESS);
    fclose(fptr);
   
   	
}

void show_error_message_and_exit(const char* msg){
	perror(msg);
	exit(1);
}

void server(int port, FILE* fptr){
// Open Server Socket
	int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(server_socket_fd<0) show_error_message_and_exit("Error opening socket!");

	// Assigning my address
	struct sockaddr_in my_address;	
	bzero((char*)&my_address, sizeof(my_address));
	my_address.sin_family = AF_INET; // Ipv4
	my_address.sin_port = htons(port);
	my_address.sin_addr.s_addr = INADDR_ANY; // connnect to all network interfaces

	// Bind socket file to the address
	if(bind(server_socket_fd, (struct sockaddr*)&my_address, sizeof(struct sockaddr))<0) show_error_message_and_exit("Error! Can't bind server to that port! Exiting..");

	// Set server socket to Listen Mode
	if(listen(server_socket_fd, BACKLOG)<0)
		show_error_message_and_exit("Error on listen.");


	while(1){	

	// Accept New Connections
	int sin_size = sizeof(struct sockaddr_in);
	struct sockaddr_in incoming_address;
	int new_connection_socket_fd = accept(server_socket_fd, (struct sockaddr *)&incoming_address, &sin_size);
	if(new_connection_socket_fd<0) show_error_message_and_exit("Error connecting to unknown.");

	int connection_pid = fork();
	fprintf(fptr,"Connected to client %s!\n", get_ip_from_address(&incoming_address));
	// Communicate - Read Write
		while(connection_pid!=0){
		
		char buffer[MAX_TRANSFER_DATA_SIZE];
		bzero(buffer,MAX_TRANSFER_DATA_SIZE);

		char* prompt_message  = "Please Enter your message: ";
		if(write(new_connection_socket_fd, prompt_message, 28)<0) show_error_message_and_exit("Error writing to socket!");

		if(read(new_connection_socket_fd, buffer, MAX_TRANSFER_DATA_SIZE)<0) show_error_message_and_exit("Error reading from socket!");
		fprintf(fptr,"%s: %s",get_ip_from_address(&incoming_address),buffer);
		fflush(fptr);
		if(buffer[0]=='E' && buffer[1]=='x' && buffer[2]=='i' && buffer[3]=='t' && buffer[4]=='!') break;
		}
		fprintf(fptr, "Exiting user %s\n", get_ip_from_address(&incoming_address));
		fflush(fptr);
		close(new_connection_socket_fd);
		if(connection_pid!=0) return;
	}
	close(server_socket_fd);
}
char* get_ip_from_address(struct sockaddr_in* addr){
	struct in_addr ipAddr = addr->sin_addr;
	char* ip = (char*)malloc(INET_ADDRSTRLEN*sizeof(char));
	inet_ntop(AF_INET,&ipAddr, ip, INET_ADDRSTRLEN);
	return ip;
}

