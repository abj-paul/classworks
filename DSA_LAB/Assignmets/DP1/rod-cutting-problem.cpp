
#include<bits/stdc++.h>
using namespace std;

// Global Variables
#define MAX_SIZE 100
int profit[MAX_SIZE],n;
int given_rod;
int max_profit[MAX_SIZE];
// Function Prototype
void take_input();
int cut_rod(int size);
void print_array(int arr[], int size);
int max(int x, int y);
// Save Pieces
struct part {
  int X;
  int Y;
};
struct part store_parts[MAX_SIZE];
void print_parts(int index);



int main()
{
for(int i=0; i<MAX_SIZE; i++) max_profit[i]=-1;
take_input();
//print_array(profit,n);
printf("The maximum profit is: %d\n",cut_rod(given_rod));
//print_array(max_profit, n);
 printf("The pieces are:\n");

 print_parts(given_rod);
 printf("Done!\n");
return 0;
}

void take_input(){
  //printf("Take Input.\n");
	scanf("%d",&n);	
	for(int i=1; i<=n; i++) scanf("%d",&profit[i]);
	scanf("%d",&given_rod);
}

int cut_rod(int size){
	if(size==0) {
		max_profit[0]=0;
		store_parts[0].X=0;
		store_parts[0].Y=0;
		return 0;
	}
	else if(size==1){
		 max_profit[1]=profit[size];
		 store_parts[1].X=0;
		 store_parts[1].X=1;
		 return max_profit[size];
	}
	if(max_profit[size]!=-1) return max_profit[size];
	else {

	  store_parts[size].X=0;
	  store_parts[size].Y=size;
		int x=-1;
		if(size<n) x=profit[size];
		max_profit[size] = max(x,max_profit[size]);
		for(int i=1; i<size/2; i++){
			x = cut_rod(size-i);
			int y = cut_rod(i);	
			int optimal_soln = x+y;
			if(max_profit[size]<optimal_soln){
			  store_parts[size].X=i;
			  store_parts[size].Y=size-i;
			}
			max_profit[size] = max(max_profit[size],optimal_soln);
			
		}
	}
	//printf("cut rod: %d-%d\n",size,max_profit[size]);
	return max_profit[size];

}

void print_array(int arr[], int size){
	for(int i=0; i<=size; i++){
		printf("%d",arr[i]);
		if(i!=size) printf(",");
	}
	printf("\n");
}

int max(int x, int y){
	if(x>y) return x;
	return y;
}

void print_parts(int index){

  // printf("----%d,%d\n",store_parts[index].X,store_parts[index].Y);
  if(store_parts[index].X==0){
    printf("%d,",store_parts[index].Y);
    return;
  }
  print_parts(store_parts[index].X);
  print_parts(store_parts[index].Y);
}
