#include<bits/stdc++.h>
using namespace std;

#define INF 1000
#define MAX_SIZE 40

//Global Variable
int matrix[MAX_SIZE][MAX_SIZE];

class Graph{
  list<pair<int, int>> *adjacency_list;

public:
  int vertices;
  Graph(int vertices);
  void addEdge(int u, int v, int w);
  void MST_prim();
};

Graph::Graph(int vertices){
  this->vertices = vertices;
  this->adjacency_list = new list<pair<int,int>>[vertices];
}

void Graph::addEdge(int u, int v, int w){
  adjacency_list[u].push_back(make_pair(v,w));
  adjacency_list[v].push_back(make_pair(u,w));
}

void Graph::MST_prim(){
  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  vector<int>minimum_distance(this->vertices, INF);
  vector<int>parent(this->vertices, -1);
  vector<bool>processed(this->vertices, false);

  int source = 0;
  pq.push(make_pair(0, source)); // because pq sorts pairs using first element by default so we put weight in first element of the pair;
  minimum_distance[source]=0;


  while(!pq.empty()){
    int u = pq.top().second;
    pq.pop();

    if(processed[u]==true) continue;

    list<pair<int,int>>::iterator i;
    for(i=adjacency_list[u].begin(); i!=adjacency_list[u].end(); ++i){
      int v = i->first;
      int weight = (*i).second;

      if(processed[v]==false && weight+minimum_distance[u]<minimum_distance[v]){
	minimum_distance[v]=weight+minimum_distance[u];
	pq.push(make_pair(minimum_distance[v], v));
	parent[v]=u;
      }
    }
    processed[u]=true;
  }

  // for(int i=1; i<vertices; i++) printf("%d - %d, %d\n", parent[i],i, minimum_distance[i]);
  for(int i=0; i<vertices; i++) printf("%d costs %d\n",i,minimum_distance[i]);
}



void convert_matrix_to_edgeList(int matrix[][MAX_SIZE], Graph* graph){
  for(int i=0; i<graph->vertices; i++){
    for(int j=0; j<graph->vertices; j++){
      if(matrix[i][j]!=-1){
	graph->addEdge(i,j,matrix[i][j]);
      }
    }
  }
}

void take_input(Graph* graph){
  for(int i=0; i<MAX_SIZE; i++)
    for(int j=0; j<MAX_SIZE; j++) matrix[i][j]=-1;

    // DONE INITIALIZING
  cin>>graph->vertices;
  for(int i=0; i<graph->vertices; i++){
    for(int j=0; j<graph->vertices; j++)  cin>>matrix[i][j];
  }
  convert_matrix_to_edgeList(matrix,graph);

}

int main()
{
	// create the graph given in above figure
	int V = 9;
	Graph g(V);
	//take_input(&g);

	 // making above shown graph
	 g.addEdge(0, 1, 4);
	 g.addEdge(0, 7, 8);
	 g.addEdge(1, 2, 8);
	 g.addEdge(1, 7, 11);
	 g.addEdge(2, 3, 7);
	 g.addEdge(2, 8, 2);
	 g.addEdge(2, 5, 4);
	 g.addEdge(3, 4, 9);
	 g.addEdge(3, 5, 14);
	 g.addEdge(4, 5, 10);
	 g.addEdge(5, 6, 2);
	 g.addEdge(6, 7, 1);
	 g.addEdge(6, 8, 6);
	 g.addEdge(7, 8, 7);

	g.MST_prim();

	return 0;
}
