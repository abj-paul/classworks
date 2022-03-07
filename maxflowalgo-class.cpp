#include <bits/stdc++.h>
#define N 200
using namespace std;

int graph[N][N] = {-1};
int residualGraph[N][N];
bool visited[N];
int parent[N];


// graph traversal bfs
bool bfs(int src, int sink){

    for(int i=0; i<N; i++){
        visited[i] = false;
    }

    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;


    while(!q.empty()){
        int x = q.front();
        //cout << x << "->";
        q.pop();

        for(int v=0; v < N ;v++){
            if(residualGraph[x][v] > 0 && visited[v] == false){
                // if current node is equal to sink
                // that means we've reached to the sink
                // from the src
                // and it denotes we have a augmented path
                // that produce a residual graph
                if (v == sink){
                    parent[v] = x;
                    return true;
                }

                // if the sink is not found
                // then simply mark the current node as visited
                // and push it into the queue for further operation
                visited[v] = true;
                parent[v] = x;
                q.push(v);

             }
        }
    }

    // it means we couldn't find any sink from our current source
    // thats why returning false
    return false;
}

int fordFulkerson(int src, int sink){

    // creating the residual graph from our original graph
    // these loop denotes we'll copy the whole graph array within
    // residual graph array....
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            residualGraph[i][j] = graph[i][j];
        }
    }

    int max_flow = 0;

    while(bfs(src, sink)){

        // it denotes the augmented path
        int path_flow = INT_MAX;

        for(int v = sink; v != src; ){

            int u = parent[v];
            path_flow = min(path_flow, residualGraph[u][v]);

            v = parent[v];
        }

        // now the following loop will update the residual graph content
        // this  will create both forward and backward edge between
        // the src and sink node for the augmented path in residual graph

        for(int v = sink; v != src; v = parent[v]){

            int u = parent[v];
            residualGraph[u][v] -= path_flow;
            residualGraph[v][u] += path_flow;

        }

        max_flow += path_flow;
    }

    return max_flow;
}


int main(){

   // freopen("in.txt", "r", stdin);

    int edge, vertex;
    cin >> edge >> vertex;

    for(int i=0; i<edge; i++){
        int n1, n2, weight;
        cin >> n1 >> n2 >> weight;

        graph[n1][n2] = weight;
    }

    int source = 0; // suppose s = 0 according to the slide
    int sink = 5; // suppose t = 5 according to the slide

    //testing output
    cout << "\nMAX FLOW: " << fordFulkerson(source, sink);

}

