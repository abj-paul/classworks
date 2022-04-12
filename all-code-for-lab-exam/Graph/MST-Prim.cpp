#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 20
#define INF 10000

class Graph {
private:
  int edges, vertices;
  int graph[MAX_SIZE][MAX_SIZE];
  int start_vertex;

  // PRIM MST
  int prev[MAX_SIZE];
public:
  Graph();
  void take_input();
  void print_input();

  void minimum_spanning_tree();
};

int main(){
  Graph graph;
  graph.take_input();
  graph.print_input();
  return 0;
}

void Graph::take_input(){
  cin>>vertices>>edges;
  int u,v,w; // u--->v with weight w
  for(int i=0; i<edges; i++){
    cin>>u>>v>>w;
    graph[u][v]=w;
  }
  cin>>start_vertex;
}

void Graph::print_input(){
  cout<<vertices<<" "<<edges<<endl;
  for(int u=0; u<vertices; u++){
    for(int v=0; v<vertices; v++){
      cout<<graph[u][v]<<" ";
    }
    cout<<endl;
  }
  cout<<start_vertex<<endl;
}

Graph::Graph(){
  for(int i=0; i<MAX_SIZE; i++)
    for(int j=0; j<MAX_SIZE; j++)
      graph[i][j]=0;
}

void Graph::minimum_spanning_tree(){
  priority_queue<int>pq;
  for(int i=0; i<vertices; i++) pq.push(INF);
  
  vector<bool> visited(this->vertices, false);

  prev[start_vertex]=-1;
  pq.push(start_vertex);
  visited[start_vertex]=true;

  while(!pq.empty()){
    int top = pq.top();
    pq.pop();
    for(int v=0; v<vertices; v++){
      if(graph[top][v]!=0) pq.push(graph[top][v]);
    }
    visited[]
  }
}
