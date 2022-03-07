#include<stdio.h>

#define f(x) (((x)*(x)*(x)) + ((4.0)*(x)*(x)) - (10.0))
#define df(x) ((3.0)*(x)*(x) + (8.0)*(x))

#define epsilon 1e-9

int main(){
	double x=1;
	int iterations=0;

	while(1){
	iterations++;
	double next_point = x - f(x)/df(x);
	if(f(next_point)<epsilon) break;
	x = next_point;	
	}

	printf("Our solution is:%lf\n",x);
	printf("Iterations needed:%d\n",iterations);

return 0;
}



