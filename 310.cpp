#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges);

/**
 * Find the minimun height tree, which means finding a node assigned as a root and it could build the min height tree.
 * 
 * - Remove all leaves(degree=1), and minus the degree of the leaf's neighbor
 * - Iterate the above step until the tree nodes <=2
 *      - Min height node can't more than 3 because the tree containing 3 nodes only has 1 min height node.
 */

class Graph {
   public:
    int V;
    list<int>* adj;
    vector<int> degree;
    vector<bool> nodes;
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
        for (int i = 0; i < V; i++) {
            nodes.push_back(true);
            degree.push_back(0);
        }
    };
    void addEdge(int v, int w) {
        degree[v]++;
        degree[w]++;
        adj[v].push_back(w);
        adj[w].push_back(v);
    };
    void showAdj() {
        for (int i = 0; i < V; i++) {
            cout << "\n"
                 << "Node: " << i << "\n";
            for (auto it = adj[i].begin(); it != adj[i].end(); ++it)
                cout << ' ' << *it;
        }
    };
    void showNode() {
        for (int i = 0; i < degree.size(); i++) {
            cout << i << "  " << degree[i] << "\n";
        }
    }
    void deleteAdjDeg(vector<int> leaf) {
        for (int i = 0; i < leaf.size(); i++) {
            V--;
            nodes[leaf[i]] = false;
            // cout << "leaf: " << leaf[i] << "\n";
            degree[leaf[i]] = 0;
            for (auto it = adj[leaf[i]].begin(); it != adj[leaf[i]].end(); ++it) {
                if (degree[*it] > 0)
                    degree[*it]--;
            }
        }
    }
};

int main() {
    vector<vector<int>> edges;
    vector<int> tmp;
    int E = 5;
    int V = 6;
    // [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
    int a[5][2] = {{0, 1}, {0, 2}, {0, 3}, {3, 4}, {4, 5}};

    for (int i = 0; i < E; i++) {
        for (int j = 0; j < 2; j++) {
            tmp.push_back(a[i][j]);
        }
        edges.push_back(tmp);
        tmp.clear();
    }
    findMinHeightTrees(V, edges);
}
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    Graph g = Graph(n);
    vector<int> root;
    for (int i = 0; i < edges.size(); i++) {
        g.addEdge(edges[i][0], edges[i][1]);
    }
    while (g.V > 2) {
        vector<int> leaf;
        for (int i = 0; i < g.degree.size(); i++) {
            if (g.degree[i] == 1) {
                leaf.push_back(i);
            }
        }
        g.deleteAdjDeg(leaf);
        g.showNode();
    }
    for (int i = 0; i < g.nodes.size(); i++) {
        if (g.nodes[i]) {
            root.push_back(i);
        }
    }
    return root;
}