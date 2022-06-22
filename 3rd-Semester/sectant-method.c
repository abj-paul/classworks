#include<math.h>
#include<stdio.h>
#define f(x) (((x)*(x)*(x))+(4)*(x)*(x)-(10.0))
#define EPSILON 1e-9

int main(){
	double a=1, b=2;
	int iterations=0;

	double c;
    	    while(1){
		//c = b - f(b)*((b-a)/(f(b)-f(a)));
		//c=(f(b)-f(a))/(b-a);
		c=(a*f(b)-b*f(a))/(f(b)-f(a));
		iterations++;
		if(fabs(f(c))<EPSILON) break;
		a=b;
		b=c;
	}

	    printf("Solution=%lf\n",c);
	    printf("Iterations=%d\n",iterations);
return 0;
}
