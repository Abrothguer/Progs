#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<int> graph[], bool seen[], int vertex){
    cout << "Arraving at " << vertex << endl;
    seen[vertex] = true;

    for (unsigned i = 0; i < graph[vertex].size(); ++i) {
        if (not seen[graph[vertex][i]]) {
            dfs(graph, seen, graph[vertex][i]);
        }
    }
}

void dfs_iterative(vector<int> graph[], bool seen[], int vertex){
    int         current;
    stack <int> dfsstk;
    dfsstk.push(vertex);

    while (not dfsstk.empty() ) {
        current = dfsstk.top();
        dfsstk.pop();
        if (seen[current]) {
            continue;
        }
        seen[current] = true;

        cout << "Visiting " << current << endl;

        for (unsigned i = 0; i < graph[current].size(); ++i) {
            if (not seen[graph[current][i]]) {
                dfsstk.push(graph[current][i]);
            }
        }
    }
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
        cout << "Type the edges: " << endl;
        for (int i = 0; i < e; ++i) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        bool seen[n];
        for (int i = 0; i < n; ++i) {
            seen[i] = false;
        }

        cout << "Recursive DFS: " << endl;
        dfs(graph, seen, 0);

        for (int i = 0; i < n; ++i) {
            seen[i] = false;
        }
        cout << "Iterative DFS: " << endl;
        dfs_iterative(graph, seen, 0);
    }
    return (0);
}
