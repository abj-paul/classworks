#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100
#define INF 10000

class Edge{
public:
  int u;
  int v;
  int w;

  bool operator<(const Edge& e);
};

class Graph{
public:
  int vertices, edges;
  Edge* edge_list;

  void take_input();
  void print_input();

  void MST_prim();
};

int main(){
  return 0;
}

bool Edge::operator<(const Edge& e){
  return this->w<e.w;
}

void Graph::MST_prim(){
  vector<int> parent(this->vertices, -1);
  vector<bool> processed(this->vertices, false);
  vector<int> key(this->vertices, INF);

  int source = this->edge_list[0].u;
  priority_queue<Edge>pq;

  // Algorithm
  pq.push(this->edge_list[0]);
  key[source]=0;

  while(!pq.empty()){
    Edge current_edge = pq.top();
    pq.pop();

    if(processed[current_edge.u])
  }
  
}
