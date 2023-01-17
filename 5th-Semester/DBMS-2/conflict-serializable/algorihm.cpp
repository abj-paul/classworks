#include<bits/stdc++.h>
using namespace std;

#define max_node 10
int getNextTransaction(vector<string> transactions, int curr_index, int num_of_transactions);
bool detectCycle(vector<vector<int>>& adj, int typeOfNode, int numOfTransaction);

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

	vector<vector<int>> graph(max_node);

	for(int i=0; i<num_of_transactions; i++){
		int current_transaction = (int)transactions[i][1] - 48;
		int other_transaction = getNextTransaction(transactions, i, num_of_transactions);
		if(other_transaction == -1 || other_transaction == current_transaction) continue;
		graph[current_transaction].push_back(other_transaction);
		//printf("DEBUG: %d->%d\n",current_transaction, other_transaction);
	}

	printGraph(graph);

	bool cycle = detectCycle(graph, typeOfNode, num_of_transactions-1);
	if(cycle==true) cout<<"Conflict Not serializable."<<endl;
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

bool iscycle(int src, vector<vector<int>>& adj, vector<bool>&visited, vector<int>&stack){
	stack[src] = true;
	if(!visited[src]){
		visited[src] = true;
		for(auto i:adj[src]){
			if(!visited[i] && iscycle(i, adj, visited, stack)) return true;
			if(stack[i]) return true;
		}
	}

	stack[src] = false;
	return false;
}

bool detectCycle(vector<vector<int>>& adj, int typeOfNode, int numOfTransaction){
	int n = typeOfNode;
	int m = numOfTransaction;

	//cout<<n<<m<<endl;

	bool cycle = false;
	vector<int> stack(n,0);
	vector<bool> visited(n,0);

	for(int i=0; i<n; i++){
		if(!visited[i] && iscycle(i,adj,visited,stack)) cycle=true;
	}
	return cycle;
}
