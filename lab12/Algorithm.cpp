#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

class Graph {
private:
    int n;
    vector<pair<int, int>> *adj; // adjacency list: (vertex, weight)
    vector<tuple<int, int, int>> edges; // (weight, u, v) for Kruskal

public:
    Graph(int V) {
        n = V;
        adj = new vector<pair<int, int>>[n];
    }

    void insert(int u, int v, int w);
    void display();
    void Delete(int u, int v);
    void prims();
    void kruskal();
    void dijkstra(int src);
};

void Graph::insert(int u, int v, int w) {
    if (u < n && v < n) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({w, u, v});
    } else {
        cout << "Out of Range" << endl;
    }
}

void Graph::display() {
    for (int i = 0; i < n; i++) {
        cout << i << " -> [";
        for (auto it : adj[i]) {
            cout << "(" << it.first << ", w=" << it.second << ") ";
        }
        cout << "]" << endl;
    }
}

void Graph::Delete(int u, int v) {
    if (u < n && v < n) {
        cout << "Deleted edge: " << u << " - " << v << endl;
        adj[u].erase(remove_if(adj[u].begin(), adj[u].end(),
            [v](pair<int, int> p) { return p.first == v; }), adj[u].end());

        adj[v].erase(remove_if(adj[v].begin(), adj[v].end(),
            [u](pair<int, int> p) { return p.first == u; }), adj[v].end());
    } else {
        cout << "Invalid range of edges" << endl;
    }
}

void Graph::prims() {
    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> inMST(n, false);
    key[0] = 0;

    for (int count = 0; count < n - 1; ++count) {
        int u = -1;
        for (int v = 0; v < n; ++v)
            if (!inMST[v] && (u == -1 || key[v] < key[u])) u = v;

        inMST[u] = true;

        for (auto [v, w] : adj[u]) {
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    cout << "Prim's MST:\n";
    for (int i = 1; i < n; ++i)
        cout << parent[i] << " - " << i << endl;
}

int find(int u, vector<int> &parent) {
    return parent[u] = (parent[u] == u ? u : find(parent[u], parent));
}

void union_sets(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = find(u, parent);
    v = find(v, parent);
    if (u != v) {
        if (rank[u] < rank[v])
            swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v])
            rank[u]++;
    }
}

void Graph::kruskal() {
    sort(edges.begin(), edges.end());
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; ++i)
        parent[i] = i;

    cout << "Kruskal's MST:\n";
    for (auto [w, u, v] : edges) {
        if (find(u, parent) != find(v, parent)) {
            cout << u << " - " << v << " (w=" << w << ")\n";
            union_sets(u, v, parent, rank);
        }
    }
}

void Graph::dijkstra(int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Dijkstra's shortest paths from " << src << ":\n";
    for (int i = 0; i < n; ++i)
        cout << "To " << i << ": " << dist[i] << endl;
}

int main() {
    Graph g(6);
    while (true) {
        cout << "\n1.Insert\n2.Display\n3.Delete\n4.Prim's\n5.Kruskal\n6.Dijkstra\n7.Exit\n";
        int choice, u, v, w;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter edge (u v weight): ";
                cin >> u >> v >> w;
                g.insert(u, v, w);
                break;
            case 2:
                g.display();
                break;
            case 3:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                g.Delete(u, v);
                break;
            case 4:
                g.prims();
                break;
            case 5:
                g.kruskal();
                break;
            case 6:
                cout << "Enter source vertex: ";
                cin >> u;
                g.dijkstra(u);
                break;
            case 7:
                cout << "Exiting...\n";
                exit(0);
        }
    }
}
