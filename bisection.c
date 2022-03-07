#include<stdio.h>

#define EPSILON 1e-9
#define f(x) (x*x*x + 4*x*x -10)

int main()
{
	double a =1, b =2;
	bisection(a, b);
	return 0;
}

void bisection(double a, double b){
	int iterations=0;
	double c;
	while(1){
		c = (a+b)/2;
		iterations++;

		if(f(c)<EPSILON) break;	
		else {
			if(f(a)*f(c)<=0) b=c;
			else a=c;
		}
	}
	printf("Solution is=%lf\n",c);
	printf("Iteratiosn required=%d\n",iterations);
}
