#include<stdio.h>
#include<unistd.h>

int input[100], size;

// Function Prototypes
void take_input();
void task_sum_of_even_numbers();
void task_count_of_even_numbers();
void task_sort_array();
void using_grand_child();

int main(){

	take_input();
	int firstChild = fork();
	int secondChild = fork();
	/* if(firstChild!=0 && secondChild!=0) */
	if(firstChild==0 && secondChild!=0) task_sum_of_even_numbers();
	else if(firstChild!=0 && secondChild==0) task_count_of_even_numbers();
	else if(firstChild==0 && secondChild==0) task_sort_array();
return 0;
}

void take_input(){
	printf("Enter array size: ");
	scanf("%d",&size);

	printf("Enter array elements(space separated):\n>>");
	for(int i=0; i<size; i++) scanf("%d",&input[i]);
}

void task_sum_of_even_numbers(){
	int sum = 0;
	for(int i=0; i<size; i++) {
		if(input[i]%2==0) sum+=input[i];
	}
	printf("Even Sum=%d. Computed by Process = %d\n",sum,getpid());
}
void task_count_of_even_numbers(){
	int count = 0;
	for(int i=0; i<size; i++) {
		if(input[i]%2==0) count++;
	}
	printf("Even Count=%d. Computed by Process = %d\n",count,getpid());
}

void task_sort_array(){
	for(int i=0; i<size-1; i++){
		for(int j=i+1; j<size; j++){
			if(input[i]>input[j]){
				int temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}
	}

	printf("Sorted Array Done. Computed by Process = %d\n",getpid());
	for(int i=0; i<size; i++) printf("%d ",input[i]);
	printf("\n");
}

void using_grand_child(){
	take_input();	
	int firstChild = fork();
	if(firstChild==0) {
		task_sum_of_even_numbers();
		int secondChild = fork();
		if(secondChild==0){
		       	task_count_of_even_numbers();
			int thirdChild = fork();
			if(thirdChild==0){
			       	task_sort_array();
			}
		}
	}
	
}
