#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include <unistd.h> // Unix Standard Files. Linux based posix & ip adresss, POSIX

#include<netinet/in.h> //for strucutre inet_addr
#include<sys/types.h> // for structure sockaddr_in
#include<sys/stat.h> // for umask 
#include<sys/socket.h>
#include <arpa/inet.h> //for inet_htop

#include "user.h"


#define BACKLOG 15
#define MAX_TRANSFER_DATA_SIZE 256 

void show_error_message_and_exit(const char* msg);
void server(int port, FILE* fptr);
char* get_ip_from_address(struct sockaddr_in* addr);

struct User* session_users[BACKLOG];
int session_user_index=0;
sem_t userMutex;

struct arg_struct{
  FILE* fptr;
  struct sockaddr_in incoming_address;
  int new_connection_socket_fd;
};

// Extra
int create_server(int port);
struct sockaddr_in receiveIncomingConnection(int server_socket_fd, int* new_connection_socket_fd);
void communicate(FILE* fptr, struct sockaddr_in incoming_address, int new_connection_socket_fd);
void closeConnection(FILE* fptr, struct sockaddr_in incoming_address, int new_connection_socket_fd);
void sendMessage(char* buffer, int sender_sockfd);
char* concatenate_string(char* a, char* s2);
void* communicationWrapper(void* args);


int main(int argc, char* argv[]){
  sem_init(&userMutex,0,1);
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
  
  /*if ((chdir("/home/abhijit/")) < 0) {
    exit(EXIT_FAILURE);
    }*/
  
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
  int server_socket_fd = create_server(port);

  pthread_t thread_id[BACKLOG];
  int i=0;
  while(1){	
    int* new_connection_socket_fd = (int*)malloc(sizeof(int));
    struct sockaddr_in incoming_address = receiveIncomingConnection(server_socket_fd, new_connection_socket_fd);

    struct arg_struct* args= (struct arg_struct*)malloc(sizeof(struct arg_struct));
    args->incoming_address = incoming_address;
    args->new_connection_socket_fd = *new_connection_socket_fd;
    args->fptr = fptr;
    pthread_create(&thread_id[i++], NULL, communicationWrapper, (void*)args);
  }
  close(server_socket_fd);
}

void* communicationWrapper(void* val){
  struct arg_struct* args = (struct arg_struct*)val;
  FILE* fptr = args->fptr;
  struct sockaddr_in incoming_address = args->incoming_address;
  int new_connection_socket_fd = args->new_connection_socket_fd;
  
  communicate(fptr, incoming_address, new_connection_socket_fd);
  closeConnection(fptr,  incoming_address, new_connection_socket_fd);
}


char* get_ip_from_address(struct sockaddr_in* addr){
	struct in_addr ipAddr = addr->sin_addr;
	char* ip = (char*)malloc(INET_ADDRSTRLEN*sizeof(char));
	inet_ntop(AF_INET,&ipAddr, ip, INET_ADDRSTRLEN);
	return ip;
}

void communicate(FILE* fptr, struct sockaddr_in incoming_address, int new_connection_socket_fd){
	int loggedIn=0; // -1 means we have just entered so we should log in
	printf("Connected to client %s!\n", get_ip_from_address(&incoming_address));
	// Communicate - Read Write
	while(1){

	  char* prompt_message;
	  struct User* user;
	  char buffer[MAX_TRANSFER_DATA_SIZE], username[MAX_TRANSFER_DATA_SIZE], passwd[MAX_TRANSFER_DATA_SIZE];
	  bzero(buffer,MAX_TRANSFER_DATA_SIZE);

	  while(loggedIn==0){
	    prompt_message = "Enter Username: ";
	    write(new_connection_socket_fd, prompt_message, strlen(prompt_message));
	    read(new_connection_socket_fd, username, MAX_TRANSFER_DATA_SIZE);
 
	    
	    prompt_message = "Enter Password: ";
	    write(new_connection_socket_fd, prompt_message, strlen(prompt_message));
	    read(new_connection_socket_fd, passwd, MAX_TRANSFER_DATA_SIZE);

	    
	    //Login
	    user = login_user(username, passwd, new_connection_socket_fd); 

	    if(user->LOGIN_STATUS==1){
	      fprintf(fptr,"%s %s",user->name,prompt_message);
	      
	      sem_trywait(&userMutex);
	      session_users[session_user_index++] = user;
	      sem_post(&userMutex);

	      for(int i=0; i<session_user_index; i++){
		if(session_users[i]->curr_sockfd==new_connection_socket_fd){
		  prompt_message = "Type \"Exit!\" to exit.\n";
		  write(session_users[i]->curr_sockfd, prompt_message, strlen(prompt_message));
		}else{
		  prompt_message = " successfully logged in!\n";
		  char* temp = concatenate_string("\n",concatenate_string(user->name, prompt_message));
		  write(session_users[i]->curr_sockfd, temp, strlen(temp));
		}
	      }

	      loggedIn=1;
	    }
	    else{
	      printf("Wrong username or password!\n(%s with length %ld,%s with length %ld)\n", username,strlen(username),passwd,strlen(passwd));
	      prompt_message = "Wrong username or password! Try again.\n";
	      write(new_connection_socket_fd, prompt_message, strlen(prompt_message));
	    }
	  }
	  /*if(loggedIn==1){
	    prompt_message  = ">> ";
	    write(new_connection_socket_fd, prompt_message, strlen(prompt_message));
	    loggedIn++;
	  }*/
	  read(new_connection_socket_fd, buffer, MAX_TRANSFER_DATA_SIZE);
	  //fprintf(fptr,"%s: %s",get_ip_from_address(&incoming_address),buffer);
	  // MESSAGE PASSING HERE

	  char* currentText = concatenate_string(concatenate_string(user->name,": "),buffer);
	  sendMessage(currentText, new_connection_socket_fd);

	  
	  fprintf(fptr,"%s: %s",user->name,buffer);
	  fflush(fptr);

	  if(buffer[0]=='q' && buffer[1]=='u' && buffer[2]=='i' && buffer[3]=='t'){
	    prompt_message = "Exiting user";
	    fprintf(fptr,"%s %s\n",prompt_message,user->name);
	    fflush(fptr);
	    break;
	  }
	}
}

void closeConnection(FILE* fptr, struct sockaddr_in incoming_address, int new_connection_socket_fd){
  printf("Exiting user %s\n", get_ip_from_address(&incoming_address));
  fflush(fptr);
  close(new_connection_socket_fd);
   return;
}

int create_server(int port){
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
  return server_socket_fd;
}

struct sockaddr_in receiveIncomingConnection(int server_socket_fd, int* new_connection_socket_fd){
  // Accept New Connections
  int sin_size = sizeof(struct sockaddr_in);
  struct sockaddr_in incoming_address;
  *new_connection_socket_fd = accept(server_socket_fd, (struct sockaddr *)&incoming_address, &sin_size);
  if(*new_connection_socket_fd<0) show_error_message_and_exit("Error connecting to unknown.");

  return incoming_address;
}


char** tokenize_sentence(char* buffer){
  char** tokens = (char**)malloc(sizeof(char*)*3);

  int semicolonEncounterd = 0, aroEncountered=0, aroEncounterSave = 0;
  char* sender = (char*)malloc(sizeof(char)*MAX_UNAME_SIZE);
  char* receiver = (char*)malloc(sizeof(char)*MAX_UNAME_SIZE);
  char* msg = (char*)malloc(sizeof(char)*MAX_MSG_SIZE);

  int sender_i=0,receiver_i=0, msg_i=0;
  for(int i=0; i<(int)strlen(buffer); i++){
    if(buffer[i]==':') {semicolonEncounterd=1; i++;}
    else if(buffer[i]=='@') {aroEncountered=1; aroEncounterSave=1;}
    else if(!semicolonEncounterd) sender[sender_i++] = buffer[i];
    else if(aroEncountered){
      if(buffer[i]==' '){ //End of name
	aroEncountered = 0;
	continue;
      }
      receiver[receiver_i++] = buffer[i];
    }
    else msg[msg_i++] = buffer[i];
  }

  //printf("Size=%ld\n%s\n%s\n",sizeof(buffer),username,msg);
  

  sender[sender_i] = '\0';
  receiver[receiver_i] = '\0';
  if(strlen(msg)!=0)msg[msg_i] = '\0';

  if(aroEncounterSave==0){
    free(sender);
    free(receiver);
    free(msg);
    free(tokens);
    return NULL; //Dummy messages. It is not intended for anyone. So we discard it.
  }
  tokens[0] = sender;
  tokens[1] = receiver;
  tokens[2] = msg;
  return tokens;
}

void sendMessage(char* buffer, int sender_sockfd){
  //  printf("DEBUG: %s\n",buffer);
  char** tokens = tokenize_sentence(buffer);
  if(tokens==NULL) return;
  
  char* prompt_message;

  int curr_user_index=0;
  for(int i=0; i<session_user_index; i++){
    if(session_users[i]->curr_sockfd==sender_sockfd) {curr_user_index=i;break;}
  }
  
  for(int i=0; i<session_user_index; i++){
    //printf("DEBUG: %s==%s?\n",session_users[i]->name, tokens[1]);
    if(strcmp(session_users[i]->name,tokens[1])==0) {
      prompt_message =concatenate_string(concatenate_string(session_users[curr_user_index]->name,": "), tokens[2]);
      write(session_users[i]->curr_sockfd, prompt_message, strlen(prompt_message));
      return;
    }
  }

  if(strcmp("all",tokens[1])==0){
    for(int i=0; i<session_user_index; i++){
      if(i!=curr_user_index) {
	printf("DEBUG: Sending @all message to user %d when curr_user_index=%d\n",i,curr_user_index);
	prompt_message = buffer;
	write(session_users[i]->curr_sockfd, prompt_message, strlen(prompt_message));
      }
    }
  }
  else{
    prompt_message = "The person you are trying to send message to, has not logged in yet!\n";
    write(sender_sockfd, prompt_message, strlen(prompt_message));
  }
  return;
}

char* concatenate_string(char* a, char* s2){
  char* s1 = (char*)malloc(sizeof(char)*(MAX_MSG_SIZE+MAX_UNAME_SIZE));
  int i=0;
  for(i=0; i<(int)strlen(a); i++)s1[i] = a[i];
  s1[i] = '\0';
  
  int length, j;
  
  // store length of s1 in the length variable
  length = 0;
  while (s1[length] != '\0') {
    ++length;
  }
  
  // concatenate s2 to s1
  for (j = 0; s2[j] != '\0'; ++j, ++length) {
    s1[length] = s2[j];
  }
  
  // terminating the s1 string
  s1[length] = '\0';
  
  //printf("After concatenation: ");
  // puts(s1);

  return s1;
}
