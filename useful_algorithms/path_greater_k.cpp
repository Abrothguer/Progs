// Finds if there is a path with distance greater or equal than k.

#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector <pair <int, int> > graph[], int source, int k, bool seen[]) {
    int vertex, weight;

    seen[source] = true;
    if (k <= 0) {
        return(true);
    }

    for (unsigned i = 0; i < graph[source].size(); ++i) {
        vertex = graph[source][i].first;
        weight = graph[source][i].second;

        if (seen[vertex]) {
            continue;
        }

        if (dfs(graph, vertex, k - weight, seen)) {
            return(true);
        }
    }

    seen[source] = false;
    return(false);
}

int main(void) {
    int n, e;

    while (true) {
        cout << "Nro of vertices: ";
        cin >> n;
        if (not n) {
            break;
        }
        cout << "Nro of edges: ";
        cin >> e;
        cout << "Type the edges and weight:" << endl;

        int a, b, w;
        vector <pair <int, int> > graph[n];

        for (int i = 0; i < e; ++i) {
            cin >> a >> b >> w;
            graph[a].push_back(make_pair(b, w));
            graph[b].push_back(make_pair(a, w));
        }

        cout << "Type k: " << endl;
        cin >> a;
        cout << "Type source node: " << endl;
        cin >> b;

        bool seen[n];
        for (int i = 0; i < n; i++) {
            seen[i] = false;
        }

        if (dfs(graph, b, a, seen)) {
            cout << "True" << endl;
        }
        else{ cout << "False" << endl; }
    }
    return(0);
}
