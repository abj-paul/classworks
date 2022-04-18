#include<bits/stdc++.h>

int states[100];
char str[100];
int current_index=0;
int size;
int flag=0;
int flag2=0;


// Prorotypes
void q0(int input);
void q1(int input);
void q2(int input);

void q0(int input){

  if(input>=size) return;
  if(flag2==0){
    flag2=1;
  }else{
   current_index++; 
   printf("q0\n");
  }
   states[current_index]=0;
   //current_index++;
  
  if(str[input]=='0'){
    q0(input+1);
  }else if(str[input]=='1'){
    q1(input+1);
  }
}


void q1(int input){
  printf("q1\n");
  if(input>=size) return;
  states[current_index]=1;
  current_index++;
  
  if(str[input]=='0'){
    q0(input+1);
  }else if(str[input]=='1'){
    if(input==size-1) {
      flag=1;
    }

    q2(input+1);
  }
}

void q2(int input){
  printf("q2\n");
  if(input>=size) return;
  states[current_index]=2;
  current_index++;
  
  if(str[input]=='0'){
    q0(input+1);
  }else if(str[input]=='1'){
    q1(input+1);
  }
}

int main(){
  printf("Enter String Size: ");
  scanf("%d",&size);
  printf("Enter a string: ");
  scanf("%s",str);

  q0(0);

  if(flag==0) printf("REJECTED\n");
  else 
      printf("ACCEPTED!\n");
  return 0;
}
