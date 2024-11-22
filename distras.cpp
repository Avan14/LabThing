#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii; 

vector<int> dijkstra(int n, int source, const vector<vector<pii>>& adj) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w); 
    }

    int source;
    cin >> source;

    vector<int> distances = dijkstra(n, source, adj);

    for (int i = 0; i < n; ++i) {
        if (distances[i] == INT_MAX) {
            cout << "INF ";
        } else {
            cout << distances[i] << " ";
        }
    }

    cout << endl;
    return 0;
}
