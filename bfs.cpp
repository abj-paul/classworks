#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define MAX_SIZE 100
// Function Prototype
void take_input(int graph[][MAX_SIZE], int row, int col, int source, int destination);
vector<int> bfs_get_path(int graph[][], int s, int d, int row, int col);

int main(){
	int graph[MAX_SIZE][MAX_SIZE], row, col, source, destination;
	take_input(graph, row, col, source, destination);
	vector<int>path = bfs_get_path(graph, source, destination, row, col);	
return 0;
}

vector<int> bfs_get_path(int graph[][], int s, int d, int row, int col){
	bool vis[10];

	queue<int>q;
	q.push(s);

	//level[s]=0;
	vector<int>path;
	path.push_back(s);
	vis[s]=0;
	while(!q.empty()){
		int current_node = q.top();
		path.push_back(current_node);
		q.pop();

		for(int i=0; i<col; i++){
			if(graph[current_node][i]!=0 && !vis[i]){
				q.push(i);
				vis[i]=true;
			}
			if(current_node==d) {
				path.push(d);
				break;
			}
		}
	}
	if(path[path.size()-1]!=d) return NULL;
	return path;
}

void take_input(int graph[][MAX_SIZE], int row, int col, int source, int destination){
	int weight,x,y;

	cin>>row>>edges;
	col=row;	
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cin>>x>>y;
			cin>>weight;
			graph[i][j]=weight;
		}
	}
	cin>>source>>destination;
}
