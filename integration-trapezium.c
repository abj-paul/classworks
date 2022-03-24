#include<stdio.h>
#include<math.h>

#define f(x) (((x)*(x))+1)

double trapezium(double a, double b, int N);

int main(){
int N=200;
double a, b;
printf("Enter a: ");
scanf("%lf",&a);
printf("Enter a: ");
scanf("%lf",&b);

double area = trapezium(a,b,N);
printf("Our area is: %lf\n",area);

return 0;
}

double trapezium(double a, double b, int N){
    double second_part = 0, fx[N+1];
    double h = fabs((b-a))/N;

    // Precomputing f(x)
    double x=a;
    for(int i=0; i<=N; i++){
        fx[i]=f(x);
        x=x+h;
    }

    // Main Formula
    for(int i=1; i<=N-1; i++){
        second_part = second_part+fx[i];
    }

    double first_part = (fx[0]+fx[N])/2;

    return (first_part+second_part)*h;
}
