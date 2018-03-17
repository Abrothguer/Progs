// Count the number of paths there is between two vertices
// that have exactly k edges using recursive implementation.

#include <vector>
#include <iostream>

using namespace std;

int count_dfs(vector<int> graph[], int src, int dest, int edges){
    // cout << "Going in with " << src << " trying to reach " << dest << " with edges = " << edges << endl;
    // cin >> l;
    if (edges < 0) {
        return 0;
    }
    if (src == dest and not edges) {
        return 1;
    }
    int cnt = 0;
    for (unsigned i = 0; i < graph[src].size(); ++i) {
        cnt += count_dfs(graph, graph[src][i], dest, edges - 1);
    }
    return cnt;
}

int main(){
    int n, e, a, b, edges;
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
        }

        cout << "Type the source: ";
        cin >> a;
        cout << "Type the destination: ";
        cin >> b;
        cout << "Type the number of edges: ";
        cin >> edges;

        cout << "There is " << count_dfs(graph, a, b, edges) << " paths "
             << "with " << edges << " edges between " << a << " and " << b << endl;
    }
    return 0;
}
