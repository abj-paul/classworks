#include<bits/stdc++.h>
#include "dfs.h"
using namespace std;

#define max_node 10
int getNextTransaction(vector<string> transactions, int curr_index, int num_of_transactions);
void printGraph(vector<vector<int>> graph);
void printVector(vector<string> v);
vector<string> take_input();

int main(){
	//string transactions[] = {"r2(x)","r3(y)","w3(x)","r1(y)","w2(x)","w1(y)","w1(x)"};
	//string transactions[] = {"r2(x)", "r3(y)", "w3(x)", "r1(y)", "w2(z)", "w1(y)", "w1(x)", "r3(z)"};
	
	vector<string> transactions = take_input();
	printVector(transactions);
	int num_of_transactions = sizeof(transactions)/sizeof(transactions[0]);

	vector<vector<int>> graph(max_node);

	for(int i=0; i<num_of_transactions; i++){
		int current_transaction = (int)transactions[i][1] - 48;
		int other_transaction = getNextTransaction(transactions, i, num_of_transactions);
		if(other_transaction == -1 || other_transaction == current_transaction) continue;
		graph[current_transaction].push_back(other_transaction);
		//printf("DEBUG: %d->%d\n",current_transaction, other_transaction);
	}

	printGraph(graph);

	Graph g(max_node);

	for(int i=0; i<graph.size(); i++){
		for(int j=0; j<graph[i].size(); j++){
			g.addEdge(i,graph[i][j]);
		}
	}

	if(g.isCyclic()) printf("Conflict not serializable.\n");
	else printf("Conflict serializable.\n");

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
	vector<string> transactions(100);
	string data = "";

	int i=0;
	while(data!="end"){
		cin>>data;
		transactions[i]	= data;
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
	for(int i=0; i<v.size(); i++) cout<< v[i] << " " << std::endl;
}
