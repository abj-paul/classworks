#include<stdio.h>
#include<unistd.h>


int main(){
	printf("This line won't be forked.\n");
	int childPid = fork();
	if(childPid==0){
		printf("I am the child process with PID %d and PPID %d.\n",getpid(), getppid());
	}else{
		printf("I am the parent process with PID %d and my Child's PID is %d.\n",getpid(), childPid);
	}
	printf("Process %d is terminating.\n",getpid());
return 0;
}
