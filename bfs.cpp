#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define MAX_SIZE 100
int graph[MAX_SIZE][MAX_SIZE], row, col, source, destination, edges;
// Function Prototype
void take_input();
vector<int> bfs_get_path(int graph[][MAX_SIZE], int s, int d, int row, int col);
vector<int>nULL;

int main(){
	nULL.push_back(-1);
	take_input();
	vector<int>path = bfs_get_path(graph, source, destination, row, col);	

	cout<<"Path is:\n";
	for(int i=0; i<path.size(); i++) cout<<path[i]<<" ";
	cout<<endl;
return 0;
}

vector<int> bfs_get_path(int graph[][MAX_SIZE], int s, int d, int row, int col){
	bool vis[10];

	queue<int>q;
	q.push(s);

	//level[s]=0;
	vector<int>path;
	path.push_back(s);
	vis[s]=0;
	while(!q.empty()){
		int current_node = q.front();
		q.pop();
		path.push_back(current_node);

		for(int i=0; i<col; i++){
			if(graph[current_node][i]!=0 && !vis[i]){
				q.push(i);
				vis[i]=true;
			}
			if(current_node==d) {
				path.push_back(d);
				break;
			}
		}
	}
	if(path[path.size()-1]!=d) return nULL;
	return path;
}

void take_input(){
	int weight,x,y;

	cin>>row>>edges;
	col=row;	
	for(int i=0; i<edges; i++){
		cin>>x>>y;
		cin>>weight;
		graph[x][y]=weight;
	}
	cin>>source>>destination;
}
