#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void bellman_ford(vector < pair<int, pair<int, int> > > edges, int n, int src){
    int v1, v2, w;
    int parent[n], distance[n];

    for (int i = 0; i < n; ++i) {
        distance[i] = INT_MAX;
    }
    distance[src] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (unsigned j = 0; j < edges.size(); ++j) {
            v1 = edges[j].second.first;
            v2 = edges[j].second.second;
            w  = edges[j].first;

            if (distance[v1] == INT_MAX) continue;
            else if (distance[v2] > distance[v1] + w) {
                distance[v2] = distance[v1] + w;
                parent[v2]   = v1;
            }
        }
    }

    cout << "Vertices shortest distance from source: " << src << endl;
    for (int i = 0; i < n; ++i) {
        if (distance[i] == INT_MAX) cout << i << " - Impossible to reach" << endl;

        cout << i << " -> " << distance[i] << "\t Path: ";
        vector <int> path;

        for (int j = i; j != src; j = parent[j]) {
            path.push_back(j);
        }

        cout << src;
        for (int j = path.size() - 1; j >= 0; --j) {
            cout << " -> " << path[j];
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

        vector < pair<int, int> >              graph [n];
        vector < pair< int, pair<int, int> > > edges;

        int                                    a, b, w;
        for (int i = 0; i < e; ++i) {
            cin >> a >> b >> w;
            graph[a].push_back(make_pair(b, w) );
            edges.push_back(make_pair(w, make_pair(a, b) ) );
        }

        cout << "Type the source: ";
        cin >> a;

        bellman_ford(edges, n, a);
    }
    return 0;
}
