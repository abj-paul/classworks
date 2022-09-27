#include <iostream>
#include <vector>

using namespace std;
int proc_cnt=0;
int rsrc_cnt=0;

vector<vector<int>> max_req;
vector<vector<int>> allocated; 
vector<vector<int>> need;

vector<int> available; //work

void take_input();
void bankers_algo();

int main()
{
    take_input();    
	bankers_algo();

    return 0;
}

void take_input(){
    int temp;
    
    cout<<"Insert number of processes: ";
    cin>>proc_cnt;
    cout<<"Insert number of resource TYPE:";
    cin>>rsrc_cnt;
    
    cout<<"Enter maximum needs for each process:\n";
    for(int i=0; i<proc_cnt; i++){
        vector<int> row;
        for(int j=0; j<rsrc_cnt; j++) {cin>>temp; row.push_back(temp);}
        max_req.push_back(row);
    }
    
    cout<<"Enter current allocations for each process:\n";
    int curr_need;
    for(int i=0; i<proc_cnt; i++){
        vector<int> row1;
        vector<int> row2;

        for(int j=0; j<rsrc_cnt; j++) {
            cin>>temp; row1.push_back(temp);
            curr_need = max_req[i][j] - row1[j];
            row2.push_back(curr_need);
        }
        allocated.push_back(row1);
        need.push_back(row2);
    }
    
    cout<<"Enter number of available instances of each resource at START:\n";
    for(int i=0; i<rsrc_cnt; i++) {cin>>temp; available.push_back(temp);}
}

bool allocation_possible(int proc){
	bool allMatch = true;
	for(int i=0; i<rsrc_cnt; i++){
		if(need[proc][i]>available[i]) allMatch = false;
	}
	return allMatch;
}

void print_vector(vector<int> v){
	for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
	cout<<endl;
}

void print_matrix(vector<vector<int>>m){
	for(int i=0; i<m.size(); i++) print_vector(m[i]);
}

void add(vector<int>a, vector<int>b, int proc){
    
    for(int i=0; i<rsrc_cnt; i++) available[i]+=allocated[proc][i];
}

void bankers_algo(){
    bool unsafe = false;
    
    int i=0, last_schedeuled=100;
	vector<int>safe_sequence;
    
    
    vector<bool> finish (proc_cnt, false);
    while(!unsafe){
        if(finish[i]==false && allocation_possible(i)){
		add(available, allocated[i], i);
		finish[i]=true;
		last_schedeuled = i;	
		safe_sequence.push_back(i);
	}
	else if(i==last_schedeuled) unsafe=true;
	i++;
	i = i%proc_cnt;
    }

     bool confirmUnsafe = false;
 	for(int i=0; i<proc_cnt; i++)
		if(finish[i]==false) {confirmUnsafe=true;break;}

	if(confirmUnsafe) printf("Unsafe state.");
	else print_vector(safe_sequence);
    
}

/* Input
5 3
7  5 3
3 2 2
9 0 2
2 2 2
4 3 3

0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

3 3 2
*/
