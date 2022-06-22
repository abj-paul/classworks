#include<bits/stdc++.h>
using namespace std;

#define INF 1e5

int  number_of_edges, number_of_vertices; //graph[MAX_SIZE][MAX_SIZE],
int flow[MAX_SIZE][MAX_SIZE];
int source, sink;

// Function Prototype
vector<int> bfs(int s, int t);
void take_input();
int FordFulkerson_MaxFlow(int S, int T);

int main(){
	take_input();
	bfs(0,4);

return 0;
}

int FordFulkerson_MaxFlow(int S, int T){
	int max_flow=0;
	// Initializing
	for(int i=0; i<number_of_vertices; i++){
		for(int j=0; j<number_of_vertices; j++){
			flow[i][j]=0;
		}
	}	

	vector<int> augmented_path = bfs(source, sink);
	while(augmented_path.size()!=0){
		// Finding bottleneck flow
		int bottleneck_flow=INF;
		for(int i=0; i<augmented_path.size()-1; i++) bottleneck_flow = min(bottleneck_flow, flow[augmented_path[i]][augmented_path[i+1]]); 
		// Subtracting bottleneck from each flow
		for(int i=0; i<augmented_path.size()-1; i++){
			int u = augmented_path[i];
			int v = augmented_path[i+1];
			flow[[u][v] = f-bottleneck_flow;

			// Adding reverese path 
			flow[v][u]+=bottleneck_flow;
		}
		max_flow+=bottleneck_flow;
	}
}

void take_input(){
	cin>>number_of_vertices;
	cin>>number_of_edges;
	for(int i=0; i<number_of_edges; i++){
		int u, v, capacity;
		cin>>u>>v>>capacity;

		flow[u][v]=capacity;
	}
	cin>>source>>sink;		
}

vector<int> bfs(int s, int t){
	vector<int>path;
	visited = new bool[number_of_vertices];
	for(int i=0; i<number_of_vertices; i++) visited[i]=false;	

	queue<int>queue;
	while(!queue.empty()){
		int curr_vertex = queue.front();
		cout<<"Visited "<<curr_vertex << " ";
		path.push_back(curr_vertex);
		queue.pop();

		int u = curr_vertex;
		for(int v=0; v<number_of_vertices; v++){
			if(flow[u][v]!=0 && !visited[v]){
				visited[v]=true;
				queue.push(v);
			}
		}
	}
	return path;
}
