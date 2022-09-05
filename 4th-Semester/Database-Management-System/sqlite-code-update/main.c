
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

int main(){
	int* buffer = (int*)malloc(sizeof(int));
	sqlite3_randomness(4, buffer);
	printf("Random: %d\n",*buffer);
return 0;
}
