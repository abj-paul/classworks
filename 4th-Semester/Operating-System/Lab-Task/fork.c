#include<stdio.h>
#include<unistd.h>



int main(){
	printf("This line won't be executed.\n");
	fork();
	fork();
	printf("Hello World!\n");
return 0;
}
