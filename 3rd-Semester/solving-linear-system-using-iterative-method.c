#include<stdio.h>
#include<math.h>


#define MAX_SIZE 100
#define EPSILON 1e-6

double a[MAX_SIZE][MAX_SIZE];
double b[MAX_SIZE];
int row=3, col=4;

double f1(double x, double y, double z){
    return (b[1]-a[1][2]*y-a[1][3]*z)/a[1][1]; // returns x
}
double f2(double x, double y, double z){
    return (b[2]-a[2][1]*x-a[2][3]*z)/a[2][2]; // returns y
}
double f3(double x, double y, double z){
    return (b[3]-a[3][1]*x-a[3][2]*y)/a[3][3]; // returns z
}

void iterative_solution();
void take_input();
void print_input();

double sum_of(int row_index);
int isDiagonallyDominant();

int main(){
    take_input();
    print_input();
    if(!isDiagonallyDominant())printf("Its not a diagonally domintated matrix!\n");
    else iterative_solution();

return 0;
}

void take_input(){
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col-1; j++){
            scanf("%lf",&a[i][j]);
        }
    }
    for(int i=1; i<=row; i++){
        scanf("%lf", &b[i]);
    }
}

void print_input(){
    printf("Matrix A is:\n");
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col-1; j++){
            printf("%lf ",a[i][j]);
        }
        printf("\n");
    }
    printf("Matrix B is:\n");;
    for(int i=1; i<=row; i++){
        printf("%lf ", b[i]);
    }
    printf("\n");
}

double sum_of(int row_index){
    double sum=0;
    for(int i=1; i<=col; i++){
        if(i!=row_index) sum+=a[row_index][i];
    }
    return sum;
}

int isDiagonallyDominant(){
    for(int i=1; i<=row; i++){
        if(a[i][i]<sum_of(i)) return 0;
    }
    return 1;
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

