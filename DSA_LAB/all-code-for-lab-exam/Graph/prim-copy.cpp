#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph
{
	int V; // No. of vertices
	list< pair<int, int> > *adj;

public:
	Graph(int V); // Constructor
	void addEdge(int u, int v, int w);
	void primMST();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair> [V];
}
void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}
void Graph::primMST(){
  priority_queue< iPair, vector <iPair> , greater<iPair> > pq; // min heap
	int src = 0; // Taking vertex 0 as source
	vector<int> minimum_weight(V, INF);

	// To store parent array which in turn store MST
	vector<int> parent(V, -1);

	// To keep track of vertices included in MST
	vector<bool> inMST(V, false);

	pq.push(make_pair(0, src));
	minimum_weight[src] = 0;

	/* Looping till priority queue becomes empty */
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		if(inMST[u] == true) continue;

		inMST[u] = true; // Include vertex in MST
		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i){
			int v = (*i).first;
			int weight = (*i).second;

			if (inMST[v] == false && minimum_weight[v] > weight){
				// Updating minimum_weight of v
				minimum_weight[v] = weight;
				pq.push(make_pair(minimum_weight[v], v));
				parent[v] = u;
			}
		}
	}

	// Print edges of MST using parent array
	for (int i = 1; i < V; ++i)
		printf("%d - %d\n", parent[i], i);
}

// Driver program to test methods of graph class
int main()
{
	// create the graph given in above figure
	int V = 9;
	Graph g(V);

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

	g.primMST();

	return 0;
}
