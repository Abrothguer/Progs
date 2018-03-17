#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs_path(vector<int> graph[], bool seen[], int path[], int src, int dest){
    if (src == dest) {
        stack<int> right_path;
        while (path[src] != -1) {
            right_path.push(path[src]);
            src = path[src];
        }
        while (not right_path.empty() ) {
            cout << right_path.top() << "->";
            right_path.pop();
        }
        cout << dest << endl;
        return;
    }

    seen[src] = true;

    for (unsigned i = 0; i < graph[src].size(); ++i) {
        if (not seen[graph[src][i]]) {
            path[graph[src][i]] = src;
            dfs_path(graph, seen, path, graph[src][i], dest);
        }
    }

    seen[src] = false;
}

int main(){
    int n, e, a, b;
    while (true) {
        cout << "Nro or vertices: ";
        cin >> n;
        if (not n) {
            break;
        }
        cout << "Nro of edges: ";
        cin >> e;

        vector<int>graph[n];
        cout << "Type the edges: " << endl;
        for (int i = 0; i < e; ++i) {
            cin >> a >> b;
            graph[a].push_back(b);
        }

        bool seen[n];
        int  path[n];

        cout << "Type the source: ";
        cin >> a;
        cout << "Type the destination: ";
        cin >> b;

        path[a] = -1;
        dfs_path(graph, seen, path, a, b);
    }
    return (0);
}
