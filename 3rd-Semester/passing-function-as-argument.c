#include<stdio.h>
#include<math.h>

double test_fun(double , double(*)(double));
double random_name(double a);

int main(){
	test_fun(2.0,&random_name);
return 0;
}


double test_fun(double x, double(*g)(double)){
	return g(x);
}

double random_name(double a){
return a*a;
}
