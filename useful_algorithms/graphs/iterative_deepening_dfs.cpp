// Iterative Deepening Depth First Search implementation

#include <iostream>
#include <vector>

using namespace std;

// Simple dfs
bool dfs(vector <int> graph[], int target, int source, int limit) {
    if (source == target) {
        cout << "Target found ";
        return(true);
    }
    if (not limit) {
        return(false);
    }

    for (unsigned i = 0; i < graph[source].size(); ++i) {
        if (dfs(graph, target, graph[source][i], limit - 1)) {
            return(true);
        }
    }
    return(false);
}

// Runs the dfs with increasing depth until target is found
// or the maximum depth is reached.
bool iddfs(vector <int> graph[], int target, int source, int max_depth) {
    for (int i = 0; i <= max_depth; ++i) {
        if (dfs(graph, target, source, i)) {
            cout << " with limit " << i << endl;
            return(true);
        }
    }
    return(false);
}

int main() {
    int n, e, a, b, src;

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
        for (int i = 0; i < e; ++i) {
            cin >> a >> b;
            graph[a].push_back(b);
        }

        cout << "Target: ";
        cin >> a;
        cout << "Maximum Depth: ";
        cin >> b;
        cout << "Source Node: ";
        cin >> src;

        if (not iddfs(graph, a, src, b)) {
            cout << "Your target " << a << " could not be found within the given depth " << b << endl;
        }
    }

    return(0);
}
