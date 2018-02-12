// Finds the transitive closure matrix of a graph.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void transitive_dfs(vector <int> graph[], int source, vector <vector <int> >&tclosure, int target) {
    int node, vertex;
    int visited[tclosure.size()];

    for (unsigned i = 0; i < tclosure.size(); ++i) {
        visited[i] = 0;
    }

    stack <int> dfsstk;
    dfsstk.push(target);

    while (not dfsstk.empty()) {
        node = dfsstk.top();
        dfsstk.pop();

        if (visited[node]) {
            continue;
        }
        tclosure[source][node] = 1;

        for (unsigned i = 0; i < graph[node].size(); ++i) {
            vertex = graph[node][i];
            if ((not visited[vertex])and(not tclosure[source][vertex])) {
                dfsstk.push(vertex);
            }
        }
    }
}

int main() {
    int n, e, a, b;

    while (true) {
        cout << "Nro of vertices: ";
        cin >> n;
        if (not n) {
            break;
        }
        cout << "Nro of edges: ";
        cin >> e;
        cout << "Type the edges:" << endl;

        vector <int>           graph [n];
        vector <vector <int> > tclosure;

        for (int i = 0; i < n; ++i) {
            vector <int> row(n, 0);
            tclosure.push_back(row);
        }

        for (int i = 0; i < e; ++i) {
            cin >> a >> b;
            graph[a].push_back(b);
        }

        for (int i = 0; i < n; ++i) {
            transitive_dfs(graph, i, tclosure, i);
        }

        cout << "The Transitive Closure Matrix of the Graph is: " << endl;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << tclosure[i][j] << " ";
            }
            cout << endl;
        }
    }
    return(0);
}
