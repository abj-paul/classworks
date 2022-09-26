#ifndef _USER_H_
#define _USER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>

extern const char* login_credentials_file;

extern sem_t accessMutex;

#define MAX_UNAME_SIZE 26
#define MAX_MSG_SIZE 100

struct User {
  char* name;
  char* passwd;
  int curr_sockfd;
  int LOGIN_STATUS; //1=success
};

// Note that user name must not have space.
void register_user(char* name, char* passwd,int curr_sockfd);
struct User* login_user(char* name, char* passwd,int curr_sockfd);
static void save_user(struct User* user);
void initialize();

void test_user();

#endif
