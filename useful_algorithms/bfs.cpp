#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int> graph[], int n, int src){
    int         current;
    bool        seen[n];
    queue <int> qubfs;
    qubfs.push(src);

    for (int i = 0; i < n; ++i) {
        seen[i] = false;
    }

    while (not qubfs.empty() ) {
        current = qubfs.front();
        qubfs.pop();
        if (seen[current]) {
            continue;
        }
        seen[current] = true;
        cout << "Visiting " << current << endl;

        for (unsigned i = 0; i < graph[current].size(); ++i) {
            if (not seen[graph[current][i]]) {
                qubfs.push(graph[current][i]);
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

        cout << "BFS: " << endl;
        bfs(graph, n, 0);
    }
    return (0);
}
