#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K);
struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

// 4
// [[0,1,1],[0,2,5],[1,2,1],[2,3,1]]
// 0
// 3
// 1


int main() {
    // int arr[3][3] = {{1, 0, 100}, {1, 2, 100}, {0, 2, 500}};
    int arr[4][3] = {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
    vector<vector<int>> x;
    vector<int> tmp;
    int n = 4, src = 0, dst = 3, K = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            tmp.push_back(arr[i][j]);
        }
        x.push_back(tmp);
        tmp.clear();
    }
    findCheapestPrice(n, x, src, dst, K);
}

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    int i, j;
    int E = flights.size();
    int dist[n];
    for (i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    struct Graph* graph = createGraph(n, E);
    for (i = 0; i < flights.size(); i++) {
        Edge tmpE;
        tmpE.src = flights[i][0];
        tmpE.dest = flights[i][1];
        tmpE.weight = flights[i][2];
        graph->edge[i] = tmpE;
        if (tmpE.src == src)
            dist[tmpE.dest] = tmpE.weight;
    }

    for (i = 0; i < K; i++) {
        for (j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v] && v == dst) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    if (dist[dst] == INT_MAX) {
        cout << -1;
    } else {
        cout << dist[dst];
    }
}