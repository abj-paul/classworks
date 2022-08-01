#include<stdio.h>
#include<unistd.h>

int main(){
	
	printf("The program has started execution.");
	fork();

	//if(getpid()==0){}
	while(1){
		// Do nothing
	}

	return 0;
}
