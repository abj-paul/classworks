#include "user.h"

sem_t accessMutex;
const char* login_credentials_file = "user-pass.txt";


void register_user(char* name, char* passwd,int curr_sockfd){
  struct User* user = (struct User*)malloc(sizeof(struct User));

  user->name = name;
  user->passwd = passwd;
  user->curr_sockfd = curr_sockfd;
  user->LOGIN_STATUS = 0;

  save_user(user);
}

static void save_user(struct User* user){
  FILE* fptr = fopen(login_credentials_file, "w");
  if(fptr==NULL) printf("Error opening file! Exiting....\n");

  fprintf(fptr, "%s,%s\n",user->name, user->passwd);
  printf("Saved user %s to registered users list.\n",user->name);
  
  fclose(fptr);
}

static void fix_string(char* buffer){
  buffer[strcspn(buffer, "\n")] = 0;
  buffer[strcspn(buffer, "\r\n")] = 0; // works for LF, CR, CRLF, LFCR, ...
}
struct User* login_user(char* name, char* passwd,int curr_sockfd){
  //Load existing users
  FILE* fptr = fopen(login_credentials_file, "r");
  if(fptr==NULL) printf("Error opening file! Exiting....\n");

  fix_string(name);
  fix_string(passwd);

  struct User* user = (struct User*)malloc(sizeof(struct User));
  user->LOGIN_STATUS = 0;

  while(!feof(fptr)){
    char registered_name[26], registered_passwd[26];
    fscanf(fptr,"%s %s",registered_name, registered_passwd);

    fix_string(registered_name);
    fix_string(registered_passwd);
  
    if(strcmp(name,registered_name)==0 && strcmp(registered_passwd, passwd)==0) {
      printf("Login successful!");
      
      user->name = name;
      user->passwd = passwd;
      user->curr_sockfd = curr_sockfd;
      user->LOGIN_STATUS = 1;
      
      return user;
    }
    printf("File: %s,%s\n",registered_name, registered_passwd);
  }
  return user;
}


void initialize(){
  sem_init(&accessMutex, 0, 1);
}
