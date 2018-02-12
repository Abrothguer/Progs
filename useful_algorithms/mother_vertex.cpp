#include <iostream>
#include <vector>

using namespace std;

// Simple dfs traversal
void dfs(vector <int> graph[], bool visited[], int node) {
    visited[node] = true;

    for (unsigned i = 0; i < graph[node].size(); ++i) {
        if (not visited[graph[node][i]]) {
            dfs(graph, visited, graph[node][i]);
        }
    }
}

int main() {
    int  n, e, a, b, latest;
    bool mother;

    while (true) {
        cout << "Nro of vertices: ";
        cin >> n;
        if (not n) {
            break;
        }
        cout << "Nro of edges: ";
        cin >> e;
        cout << "Type the edges:" << endl;

        vector <int> graph[n];

        // Scans the graph.
        for (int i = 0; i < e; ++i) {
            cin >> a >> b;
            graph[a].push_back(b);
        }

        bool visited[n];
        for (int i = 0; i < n; ++i) {
            visited[i] = false;
        }

        // Traverses the graph keeping track of the latest source node.
        // By property of DFS the latest source node to complete it might
        // be a mother vertex cause maybe it can reach all of the others.
        for (int i = 0; i < n; ++i) {
            if (not visited[i]) {
                dfs(graph, visited, i);
                latest = i;
            }
        }

        for (int i = 0; i < n; ++i) {
            visited[i] = false;
        }

        // Checking if the node found is indeed a mother node
        // calling dfs again.
        mother = true;
        dfs(graph, visited, latest);

        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            mother = false;
            break;
        }

        if (mother) {
            cout << "A mother vertex in your graph is " << latest << endl;
        }
        else{
            cout << "There is not mother vertex in your graph" << endl;
        }
    }
}
