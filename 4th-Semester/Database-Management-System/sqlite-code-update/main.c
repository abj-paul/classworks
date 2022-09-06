
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

int main(){
        //sqlite3_vfs vfs;
	//vfs.xFullPathname = SQLITE_OK;
	//vfs.xOpen = SQLITE_OK;

        sqlite3 *db;
        int rc = sqlite3_open(":memory:", &db);

	int* buffer = (int*)malloc(sizeof(int));
	sqlite3_randomness(4, buffer);
	printf("Random: %d\n",*buffer);
return 0;
}
