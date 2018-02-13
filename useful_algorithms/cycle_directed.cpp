#include <iostream>
#include <vector>

using namespace std;

bool cycle_check(vector <int> graph[], bool seen[], int current) {
    seen[current] = true;

    for (unsigned i = 0; i < graph[current].size(); ++i) {
        if (seen[graph[current][i]]) {
            return(true);
        }
        if (cycle_check(graph, seen, graph[current][i])) {
            return(true);
        }
    }
    return(false);
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

        vector <int> graph[n];
        for (int i = 0; i < e; ++i) {
            cin >> a >> b;
            graph[a].push_back(b);
        }

        bool seen[n];
        for (int i = 0; i < n; ++i) {
            seen[i] = false;
        }

        if (cycle_check(graph, seen, 0)) {
            cout << "There is a cycle in your graph!" << endl;
        }
        else{
            cout << "There is no cycle in your graph!" << endl;
        }
    }
    return(0);
}
