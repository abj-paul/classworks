#include<stdio.h>
#include<unistd.h>

int main(){
	printf("I am the original process with PID %d and PPID %d.\n",getpid(), getppid());

	int childPid = fork(); // Child process is being created.
	if(childPid!=0){
		printf("I am the parent process with PID %d and PPID %d.\n",getpid(), getppid());
		printf("My child's pid is %d\n",childPid);
	}else{
		printf("I am the child process with PID %d and PPID %d.\n",getpid(), getppid());
	}
	printf("Process %d terminates here.\n",getpid());
return 0;
}
