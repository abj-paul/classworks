#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
  int u;
  int v;
  int w;
};

class Graph{
public:
  int vertices, edges;
  Edge* edge_list;

  void take_input();
  void print_input();
  void MST_Kruskal();
};

class DisjointSet{
public:
  int* parent;
  int* rank;
  int size;

  DisjointSet(int size);
  int find(int vertex);
  void union_disjoint_sets(int vertex_1, int vertex_2);
};

int compare(Edge e1, Edge e2);
void print_edge_list(Edge* edge_list, int size);

int main(){
  Graph* graph = new Graph;
  graph->take_input();
  //graph->print_input();
  printf("MST is:\n");
  graph->MST_Kruskal();
  return 0;
}

DisjointSet::DisjointSet(int size){
  this->size = size;
  parent = new int[size+1];
  rank = new int[size+1];
  
  for(int i=0; i<=size; i++){
    parent[i]=i;
    rank[i]=0;
  }
}

int DisjointSet::find(int vertex){ // Returns root of the set/current Tree
  if(vertex!=this->parent[vertex]) parent[vertex] = find(this->parent[vertex]);
  return parent[vertex];
}


void DisjointSet::union_disjoint_sets(int vertex_1, int vertex_2){
  int root_1 = find(vertex_1);
  int root_2 = find(vertex_2);

  if(rank[root_1]>rank[root_2]) parent[root_2] = root_1;
  else parent[root_1] = root_2;


  if(rank[root_1]==rank[root_2]) rank[root_2]++; //parent and child can not be of the same rank!
}

int compare(Edge e1, Edge e2){
  return e1.w < e2.w;
}

void Graph::MST_Kruskal(){
  // sort edges
  sort(this->edge_list, this->edge_list+this->edges, compare);

  DisjointSet ds(this->edges);
  Edge* output = new Edge[this->edges];
  int j=0;
  // The algorithm
  for(int i=0; i<this->edges; i++){
    Edge current_edge = this->edge_list[i];

    if(ds.find(current_edge.u)!=ds.find(current_edge.v)){
      ds.union_disjoint_sets(current_edge.u, current_edge.v);
      output[j]=current_edge;
      j++;
    }
  }

  print_edge_list(output, j);
}

void print_edge_list(Edge* edge_list, int size){
  for(int i=0; i<size; i++){
    printf("%d %d %d\n",edge_list[i].u, edge_list[i].v, edge_list[i].w);
  }
}

void Graph::print_input(){
  printf("%d %d\n",this->vertices, this->edges);
  print_edge_list(this->edge_list, this->edges);
}

void Graph::take_input(){
  cin>>this->vertices>>this->edges;
  this->edge_list = new Edge[this->edges];
  int u,v,w;
  for(int i=0; i<this->edges; i++){
    cin>>u>>v>>w;
    Edge* edge = new Edge;
    edge->u=u;
    edge->v=v;
    edge->w=w;
    this->edge_list[i]=*edge;
  }
}
