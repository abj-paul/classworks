#include<stdio.h>
#include<stdlib.h>

#define ROW 3
#define COL 300000

int main(){
	int mat[ROW][COL];
	
	time_t curr_time;
	srand((unsigned) time(&curr_time));

	for(int i=0; i<ROW; i++){
		for(int j=0; j<COL; j++){
			int val = rand() % 50;
			if(val<10 || val>40) mat[i][j]=1; 	
			else mat[i][j]=val;

	//		mat[i][j]=1;
		}
	}

	for(int i=0; i<ROW;  i++){
		for(int j=0; j<COL; j++) printf("%d ",mat[i][j]);
		printf("\n");
	}


return 0;
}
