#include<stdio.h>
#include<math.h>

#define f_old(x) fabs((2)*(sin(x)))
#define PI 3.14159265

double simpson(double a, double b, int N);

int main(){
int N=200;
double a, b;
printf("Enter a: ");
scanf("%lf",&a);
printf("Enter a: ");
scanf("%lf",&b);

double area = simpson(a,b,N);
printf("Our area is: %lf\n",area);

return 0;
}

double simpson(double a, double b, int N){
    double fx[N+1];
    double h = (fabs((b-a))/N);

    // Precomputing f(x)
    double x=a;
    for(int i=0; i<=N; i++){
        fx[i]=f(x);
        x=x+h;
    }

    // Main Formula
    double odd_part=0;
    for(int i=1; i<N; i=i+2){
        odd_part = odd_part+fx[i];
    }
    double even_part=0;
    for(int i=2; i<N; i=i+2){
        even_part = even_part+fx[i];
    }

    double first_part = (fx[0]+fx[N]);

    return (h/3)*(first_part+2*even_part+4*odd_part);
}

