#include<stdio.h>
#include<math.h>

#define f(x) ((x)*(sin(x)))
void get_axis(double start, double end, int number_of_points);

int main(){
double a = 0;
double b = 4*3.1416;
get_axis(a,b,200);
return 0;
}

void get_axis(double start, double end, int number_of_points){

    double x = start;
    double h = fabs(start-end)/number_of_points;

    for(int i=0; i<number_of_points-1; i++){
            printf("%lf,%lf\n",x,f(x));
            x=x+h;
    }
}
