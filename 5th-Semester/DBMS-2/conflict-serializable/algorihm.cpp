#include<bits/stdc++.h>
using namespace std;

#define max_node 10

bool Cycle=false;
int visited[max_node];
vector<vector<int>> graph(max_node);


int getNextTransaction(vector<string> transactions, int curr_index, int num_of_transactions);
void dfs(int node);

// Utility
void printGraph(vector<vector<int>> graph);
void printVector(vector<string> v);
vector<string> take_input();

int main(){
	//string transactions[] = {"r2(x)","r3(y)","w3(x)","r1(y)","w2(x)","w1(y)","w1(x)"};
	//string transactions[] = {"r2(x)", "r3(y)", "w3(x)", "r1(y)", "w2(z)", "w1(y)", "w1(x)", "r3(z)"};
	
	int typeOfNode;
	cin>>typeOfNode;
	vector<string> transactions = take_input();
	//printVector(transactions);
	int num_of_transactions = transactions.size();



	for(int i=0; i<num_of_transactions; i++){
		int current_transaction = (int)transactions[i][1] - 48;
		int other_transaction = getNextTransaction(transactions, i, num_of_transactions);
		if(other_transaction == -1 || other_transaction == current_transaction) continue;
		graph[current_transaction].push_back(other_transaction);
		//printf("DEBUG: %d->%d\n",current_transaction, other_transaction);
	}

	printGraph(graph);

	   for(int i=1;i<typeOfNode;i++)
	    {
		if(visited[i]==0)
		{
		    dfs(i);
		}
	    }

	if(Cycle==true) cout<<"Conflict Not serializable."<<endl;
	else cout << "Conflict serializable"<<endl ;

return 0;
}

void printGraph(vector<vector<int>> graph){
	printf("Graph: \n");
	for(int i=0; i<graph.size(); i++){
		if(graph[i].size()!=0){
			printf("%d: ",i);
			for(int j=0; j<graph[i].size(); j++){
				printf("%d ",graph[i][j]);
			}
			printf("\n");
		}
	}
}

vector<string> take_input(){
	vector<string> transactions;
	string data = "";

	while(data!="end"){
		cin>>data;
		transactions.push_back(data);
	}

	return transactions;
}

int getNextTransaction(vector<string> transactions, int curr_index, int num_of_transactions){
	char data_entity = transactions[curr_index][3];
	char transaction_type = transactions[curr_index][0];

	int next_transaction = -1;
	for(int i=curr_index+1; i<num_of_transactions; i++){
		if(transactions[i][3]==data_entity) {
			if(transaction_type=='w' || (transaction_type=='r' && transactions[i][0]=='w')){
				next_transaction = (int)transactions[i][1] - 48;
				break;
			}
		}
	}

	return next_transaction;
}
void printVector(vector<string> v){
	for(int i=0; i<v.size(); i++) cout<<i<<")"<< v[i] << " " << std::endl;
}

void dfs(int node){
    visited[node]=1;
    for(auto x: graph[node]){   
        if(visited[x]==0)dfs(x);
        if(visited[x]==1){
            Cycle=true;
            return;
        }
        if(visited[x]==2)continue;
    }
    visited[node]=2;
}
