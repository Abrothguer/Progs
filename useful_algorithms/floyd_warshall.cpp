#include <iostream>
#include <vector>
#include <iomanip>
#include <limits.h>

using namespace std;

void floyd_warshall(vector < pair<int, int> > graph [], int n){
    int distance[n][n];
    //int path[n][n];

    // Clears the distance matrix.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            distance[i][j] = i == j ? 0 : INT_MAX;
        }
    }

    // Initializes the matrix with the weight of the edges.
    for (int i = 0; i < n; ++i) {
        for (unsigned j = 0; j < graph[i].size(); ++j) {
            distance[i][graph[i][j].first] = graph[i][j].second;
        }
    }

    // Calculates the shortest path.
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (distance[i][k] == INT_MAX or distance[k][j] == INT_MAX) {
                    continue;
                }
                if (distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // Prints the result
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (distance[i][j] == INT_MAX) cout << setw(5) << "INF";
            else cout << setw(5) << distance[i][j];
        }
        cout << endl;
    }
}

int main(){
    int n, e;
    while (true) {
        cout << "Nro of vertices: ";
        cin >> n;
        if (not n) {
            break;
        }
        cout << "Nro of edges: ";
        cin >> e;
        cout << "Type the edges and weights:" << endl;

        vector < pair<int, int> > graph [n];
        int                       a, b, w;

        for (int i = 0; i < e; ++i) {
            cin >> a >> b >> w;
            graph[a].push_back(make_pair(b, w) );
        }
        floyd_warshall(graph, n);
    }

    return 0;
}
