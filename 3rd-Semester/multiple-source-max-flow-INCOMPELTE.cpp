#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100
#define INT_MAX 100

// Input Variables
void take_input();
int edges, vertices, graph[MAX_SIZE][MAX_SIZE];
int source, destination;
int sources[MAX_SIZE];

// Function Prototypes
bool bfs(int rGraph[][MAX_SIZE],int source, int destination, int parent[]);
int fordFulkerson(int graph[][MAX_SIZE], int source, int destination);

int sum_of_flow(int vertex);
void make_new_source();
void initialize();

int main(){
  initialize();
  take_input();
  make_new_source();
  printf("Max Flow=%d\n",fordFulkerson(graph, source, destination));
  return 0;
}

bool bfs(int rGraph[][MAX_SIZE],int source, int destination, int parent[]){
  bool visited[MAX_SIZE];
  memset(visited, false, sizeof(visited));
  for(int i=0; i<vertices; i++) parent[i]=i;

  queue<int>q;
  q.push(source);
  visited[source]=true;

  while(!q.empty()){
    int u = q.front();
    q.pop();
    
    for(int v=0; v<vertices; v++){
      if(visited[v]==false && rGraph[u][v]>0){
	if(v==destination){
	  parent[v]=u;
	  return true;
	}
	
	visited[v]=true;
	q.push(v);
	parent[v]=u;
      }
    }
  }
  return false;
}

int fordFulkerson(int graph[][MAX_SIZE], int source, int destination){
  int max_flow=0;

  int rGraph[MAX_SIZE][MAX_SIZE];
  for(int i=0; i<vertices; i++){
    for(int j=0; j<vertices; j++) rGraph[i][j]=graph[i][j];
  }

  // Algorithm
  int parent[MAX_SIZE];
  while(bfs(rGraph, source, destination, parent)){

    int  minimum_flow = INT_MAX;
    for(int v=destination; v!=source; v=parent[v]){
      int u = parent[v];
      minimum_flow = min(minimum_flow, rGraph[u][v]);
    }
    for(int v=destination; v!=source; v=parent[v]){
      int u = parent[v];
      rGraph[u][v]-=minimum_flow;
      rGraph[v][u]+=minimum_flow;
    }
    max_flow+=minimum_flow;
  }
  return max_flow;
}

void take_input(){
  cin>>vertices>>edges;
  for(int i=1; i<=vertices; i++){
    for(int j=1; j<=vertices; j++) scanf("%d",&graph[i][j]);
  }
  cin>>source>>destination;
}

int sum_of_flow(int vertex){
  int sum=0;
  for(int i=1; i<=vertices; i++){
    sum+=graph[vertex][i];
  }
  return sum;
}

void make_new_source(){
  int source_index = 0;
  // graph[0][0]=0;
  for(int v=1; v<=vertices; v++){
    graph[source_index][v] = sum_of_flow(v);
  }
  vertices++;
}

void initialize(){
  for(int i=0; i<MAX_SIZE; i++){
    for(int j=0; j<MAX_SIZE; j++) graph[i][j]=0;
  }
}
