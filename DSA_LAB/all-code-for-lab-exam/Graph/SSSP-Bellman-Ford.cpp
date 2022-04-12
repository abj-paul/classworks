#include<bits/stdc++.h>
using namespace std;

#define INF 10000

class Edge {
public:
  int u;
  int v;
  int w;
};

class Graph{
public:
  int vertices;
  int edges;
  Edge* edge_list;
};

// Function Prototype
void take_input(Graph* graph);
void print_vector(vector<int>v);
void Bellman_ford(Graph* graph, int source_vertex);

int main(){
  Graph* graph = new Graph;
  take_input(graph);
  Bellman_ford(graph, 0);
  return 0;
}

void take_input(Graph* graph){
  graph->vertices=5;
  graph->edges=8;
  graph->edge_list = new Edge[8];

 //edge 0 --> 1
  graph->edge_list[0].u = 0;
  graph->edge_list[0].v = 1;
  graph->edge_list[0].w = 5;

  //edge 0 --> 2
  graph->edge_list[1].u = 0;
  graph->edge_list[1].v = 2;
  graph->edge_list[1].w = 4;

  //edge 1 --> 3
  graph->edge_list[2].u = 1;
  graph->edge_list[2].v = 3;
  graph->edge_list[2].w = 3;

  //edge 2 --> 1
  graph->edge_list[3].u = 2;
  graph->edge_list[3].v = 1;
  graph->edge_list[3].w = 6;

  //edge 3 --> 2
  graph->edge_list[4].u = 3;
  graph->edge_list[4].v = 2;
  graph->edge_list[4].w = 2;
}

void Bellman_ford(Graph* graph, int source_vertex){
  vector<int>distance(graph->vertices, INF);

  distance[source_vertex]=0;

  for(int i=0; i<=graph->vertices-1; i++){
    for(int j=0; j<graph->edges; j++){
      int u = graph->edge_list[j].u;
      int v = graph->edge_list[j].v;
      int w = graph->edge_list[j].w;

      if(distance[u]!=INF && distance[u]+w < distance[v]) distance[v]=distance[u]+w;
    }
  }

  // Detect Negative Cycle
  for(int i=0; i<graph->edges; i++){
      int u = graph->edge_list[i].u;
      int v = graph->edge_list[i].v;
      int w = graph->edge_list[i].w;

      if(distance[u]!=INF && distance[u]+w<distance[v]){
	printf("The graph contains negative weight cycle. So SSSP is not possible.\n");
	return;
      }
  }

  printf("Single Source Shortest Path using Bellman-Ford:\n");
  print_vector(distance);
}

void print_vector(vector<int>v) {
  for (int i = 0; i < v.size(); i++){
    if(v[i]==INF) printf("I ");
    else printf("%d ", v[i]);
  }
  printf("\n");
}
