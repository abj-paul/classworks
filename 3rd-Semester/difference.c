#include<stdio.h>
#include<math.h>

#define f(x) (((x)*(x)*(x)) + (4*(x)*(x)) - 10)
#define df(x) ((3*(x)*(x)) + 8*(x))

#define MAX_SIZE 300
double x[MAX_SIZE+1], fx[MAX_SIZE+1], df[MAX_SIZE+1], calculated_df[MAX_SIZE+1], h=0;

double forward_difference(int index);
double backward_difference(int index);
double central_difference(int index);

void print_result(double left, double right);
void build_difference_table(double left, double right);
double max(double a, double b);



int main(){
	build_difference_table((double)0,(double)10);
	print_result(0,10);

return 0;
}


double forward_difference(int index){
	return ((fx[index+1]-fx[index])/h);
}

double backward_difference(int index){
	return ((fx[index]-fx[index-1])/h);
}

double central_difference(int index){
	return ((fx[index+1]-fx[index-1])/(2*h));
}

void build_difference_table(double left, double right){
	h = (right-left)/MAX_SIZE;

	// Finding Values for X,f(x)
	x[0]=left;
	fx[0]=f(left);
	for(int i=1; i<=MAX_SIZE; i++){
		 x[i]=x[i-1]+h;
		fx[i] = f(x[i]);
	}

	// printing X
	//for(int i=0; i<=MAX_SIZE; i++) printf("(%d,%lf) ",i,x[i]);
	//printf("\n");

	//Finding df
	df[0]=forward_difference(0);
	int i;
	for(i=1; i<MAX_SIZE; i++){
		df[i] = central_difference(i);
	}
	df[i]=backward_difference(i);


	// Calculated Differnce
	for(int i=0; i<=MAX_SIZE; i++){
		calculated_df[i]=df(x[i]);		
	}
}


void print_result(double left, double right){
	printf("The bound is[%lf,%lf]\n",left,right);

	double max_difference=0;
	for(int i=0; i<=MAX_SIZE; i++)
	{
		max_difference = max(max_difference, fabs(df[i]-calculated_df[i]));
		printf("%d) x=%lf, f(x)=%lf, df(x)=%lf, calculated_df=%lf, max=%lf\n",i+1, x[i],fx[i],df[i],calculated_df[i], max(calculated_df[i],df[i]));
	}

	printf("Max Difference = %lf\n",max_difference);
}

double max(double a, double b){
	if(a>=b) return a;
	else return b;
}

