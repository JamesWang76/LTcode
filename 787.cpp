#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K);
struct Edge{
    int node, weight;
};


class Graph {
    int V;  // No. of vertices
    // Pointer to an array containing adjacency
    // lists
    list<Edge>* adj;

   public:
    int* step;
    int* dist;
    Graph(int V);  // Constructor

    // function to add an edge to graph
    void addEdge(int v, Edge w);

    // prints BFS traversal from a given source s
    void BFS(int s, int d, int K);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<Edge>[V];
    this->step = new int[V];
    memset(this->step, -1, V * sizeof(int));
    this->dist = new int[V];
    for(int i=0;i<V;i++){
        this->dist[i] = INT_MAX;
    }
}

void Graph::addEdge(int v, Edge w) {
    adj[v].push_back(w);  // Add w to v’s list.
}

void Graph::BFS(int s, int d, int K) {
    list<int> queue;
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    queue.push_back(s);
    this->step[s] = 0;
    this->dist[s] = 0;
    list<Edge>::iterator i;

    while (!queue.empty()) {
        s = queue.front();
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[i->node]) {
                if(adj[i->node].size() != 0)
                    visited[i->node] = true;
                this->step[i->node] = (this->step[s]) + 1;
                if(this->dist[i->node] > this->dist[s] + i->weight){
                    this->dist[i->node] = this->dist[s] + i->weight;
                }
                queue.push_back(i->node);
            }
        }
        if(this->step[d] > K){
            cout<<this->dist[d]<<"\n";
            break;
        }
    }
    cout<<this->dist[d]<<"\n";
}

int main() {
    // int arr[3][3] = {{0, 1, 100}, {1, 2, 100}, {0, 2, 90}};
    int arr[24][3] = {{3,4,4},{2,5,6},{4,7,10},{9,6,5},{7,4,4},{6,2,10},{6,8,6},{7,9,4},{1,5,4},{1,0,4},{9,7,3},{7,0,5},{6,5,8},{1,7,6},{4,0,9},{5,9,1},{8,7,3},{1,2,6},{4,1,5},{5,2,4},{1,9,1},{7,8,10},{0,4,2},{7,2,8}};
    vector<vector<int>> x;
    vector<int> tmp;
    int n = 10, src = 6, dst = 0, K = 7;

    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 3; j++) {
            tmp.push_back(arr[i][j]);
        }
        x.push_back(tmp);
        tmp.clear();
    }
    findCheapestPrice(n, x, src, dst, K);
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    int i, j;
    Graph g(n);
    for (i = 0; i < flights.size(); i++) {
        Edge e;
        e.node = flights[i][1];
        e.weight = flights[i][2];
        g.addEdge(flights[i][0], e);
    }
    g.BFS(src, dst, K);
}
