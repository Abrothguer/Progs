#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector <int> topsort(vector <pair <int, int> > graph[], int n) {
    queue <int>  qusort;
    vector <int> sorted;
    int          indegree[n];
    int          vertex;

    for (int i = 0; i < n; ++i) {
        indegree[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        for (unsigned j = 0; j < graph[i].size(); ++j) {
            indegree[graph[i][j].first]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (not indegree[i]) {
            qusort.push(i);
        }
    }

    while (not qusort.empty()) {
        vertex = qusort.front();
        qusort.pop();
        sorted.push_back(vertex);

        for (unsigned i = 0; i < graph[vertex].size(); ++i) {
            indegree[graph[vertex][i].first]--;
            if (not indegree[graph[vertex][i].first]) {
                qusort.push(graph[vertex][i].first);
            }
        }
    }

    return(sorted);
}

void shortest_dag(vector <pair <int, int> > graph[], int src, int n) {
    vector <int> sorted;
    int          weights[n];
    int          vertex, weight;

    for (int i = 0; i < n; ++i) {
        weights[i] = INT_MAX;
    }

    sorted       = topsort(graph, n);
    weights[src] = 0;

    for (int i = 0; i < n; ++i) {
        if (weights[i] == INT_MAX) {
            continue;
        }

        for (unsigned j = 0; j < graph[i].size(); ++j) {
            vertex = graph[i][j].first;
            weight = graph[i][j].second;

            if (weights[vertex] > weights[i] + weight) {
                weights[vertex] = weights[i] + weight;
            }
        }
    }


    cout << "Shortest paths from source = " << src << endl;
    for (int i = 0; i < n; ++i) {
        if (weights[i] == INT_MAX) {
            cout << i << " - There is no way to reach the vertex" << endl;
        }
        else{
            cout << i << " -> " << weights[i] << endl;
        }
    }
}

int main() {
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
        }

        cout << "Type the source: ";
        cin >> a;
        shortest_dag(graph, a, n);
    }
    return(0);
}
