#include<stdio.h>
#include<math.h>

#define f1(x,y,z) ((85-3*(y)+2*(z))/15)
#define f2(x,y,z) ((51-2*(x)-z)/10)
#define f3(x,y,z) ((5-(x)+2*(y))/8)

#define EPSILON 1e-9

void iterative_solution();

int main(){

    iterative_solution();
return 0;
}

void iterative_solution(){
    double x_old=0, y_old=0, z_old=0;
    double x_new, y_new, z_new;
    double x_error, y_error, z_error;

    int iteration_count=0;
    while(1){
        x_new = f1(x_old, y_old, z_old);
        y_new = f2(x_old, y_old, z_old);
        z_new = f3(x_old, y_old, z_old);

        x_error = fabs(x_old-x_new);
        y_error = fabs(y_old-y_new);
        z_error = fabs(z_old-z_new);

        iteration_count++;

        if(x_error<EPSILON && y_error<EPSILON && z_error<EPSILON){
            printf("x=%lf, y=%lf, z=%lf\n",x_new, y_new, z_new);
            printf("Iteration required=%d\n",iteration_count);
            break;
        }else{
            x_old = x_new;
            y_old = y_new;
            z_old = z_new;
        }
    }
}

