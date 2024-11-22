#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int primMST(const vector<vector<int>>& graph, int n) {
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    key[0] = 0;
    int totalWeight = 0;

    for (int count = 0; count < n; ++count) {
        int u = -1;

        for (int i = 0; i < n; ++i) {
            if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        inMST[u] = true;
        totalWeight += key[u];

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    cout << primMST(graph, n) << endl;
    return 0;
}
