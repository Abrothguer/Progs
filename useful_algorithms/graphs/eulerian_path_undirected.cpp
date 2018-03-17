// Checks if an undirected graph has a eulerian path.

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void dfs(vector<int> graph[], bool seen[], int vertex){
    seen[vertex] = true;

    for (unsigned i = 0; i < graph[vertex].size(); ++i) {
        if (not seen[graph[vertex][i]]) {
            dfs(graph, seen, graph[vertex][i]);
        }
    }
}

bool eulerian_path(vector<int> graph[], int n){
    int  odds = 0;
    bool seen[n];
    for (int i = 0; i < n; ++i) {
        seen[i] = false;
    }

    int vertex = -1;
    for (int i = 0; i < n; ++i) {
        if (graph[i].size() ) {
            vertex = i;
            break;
        }
    }

    if (vertex == -1) {
        return (true);
    }

    dfs(graph, seen, vertex);

    for (int i = 0; i < n; ++i) {
        odds += graph[i].size() % 2;
        if (not seen[i] and graph[i].size() ) {
            return (false);
        }
    }
    if (odds == 0 or odds == 2) {
        return (true);
    }
    return (false);
}

int main(){
    int n, e, a, b;

    while (true) {
        cout << "Nro of vertices: ";
        cin >> n;
        if (not n) {
            break;
        }
        cout << "Nro of edges: ";
        cin >> e;

        vector <int> graph[n];
        for (int i = 0; i < e; ++i) {
            cin >> a >> b;
            graph[b].push_back(a);
            graph[a].push_back(b);
        }

        if (eulerian_path(graph, n) ) {
            cout << "There is an eulerian path in your graph" << endl;
        }
        else{
            cout << "There is not an eulerian path in your graph" << endl;
        }
    }

    return (0);
}
