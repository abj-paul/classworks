#include <bits/stdc++.h>
using namespace std;
 
#define MAX_SIZE 4
#define INF 1000
 
void floydWarshall(int graph[][MAX_SIZE], int vertices);
void printSolution(int dist[][MAX_SIZE], int vertices);
 
int main(){
  int graph[MAX_SIZE][MAX_SIZE] = { { 0, 5, INF, 10 },
		      { INF, 0, 3, INF },
		      { INF, INF, 0, 1 },
		      { INF, INF, INF, 0 } };
  
  floydWarshall(graph, 4);
  return 0;
}
 

void floydWarshall(int graph[][MAX_SIZE], int vertices){
    int dist[MAX_SIZE][MAX_SIZE];

    for(int i = 0; i < vertices; i++)
        for(int j = 0; j < vertices; j++)
            dist[i][j] = graph[i][j];

    for(int k = 0; k < vertices; k++) {
        // Pick all vertices as source one by one
        for(int i = 0; i < vertices; i++) {
            // Pick all vertices as destination for the above picked source
            for(int j = 0; j < vertices; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if( dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF) )
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist, vertices);
}
 
void printSolution(int dist[][MAX_SIZE], int vertices){
    cout << "The following matrix shows the shortest distances between every pair of vertices \n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (dist[i][j] == INF) cout << "I"<< " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
