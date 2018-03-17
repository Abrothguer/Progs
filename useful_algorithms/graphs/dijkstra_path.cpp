#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

void dijkstra_path(vector <pair <int, int> > graph[], int src, int n) {
    bool seen[n];
    int  distance[n], path[n];
    int  vertex, weight, value, dist;

    for (int i = 0; i < n; ++i) {
        seen[i]     = false;
        distance[i] = INT_MAX;
        path[i]     = -1;
    }

    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
    distance[src] = 0;
    pq.push(make_pair(0, src));

    while (not pq.empty()) {
        vertex = pq.top().second;
        dist   = pq.top().first;
        pq.pop();

        if (seen[vertex]) {
            continue;
        }
        seen[vertex] = true;

        for (unsigned i = 0; i < graph[vertex].size(); ++i) {
            value  = graph[vertex][i].first;
            weight = graph[vertex][i].second;

            if (distance[value] > dist + weight) {
                distance[value] = dist + weight;
                pq.push(make_pair(distance[value], value));
                path[value] = vertex;
            }
        }
    }

    cout << "Shortest path from source " << src << endl;
    for (int i = 0; i < n; ++i) {
        if (distance[i] == INT_MAX) {
            cout << i << " - Impossible to reach" << endl;
            continue;
        }
        cout << i << " -> " << distance[i] << "\t Path: ";
        vector <int> vertices;

        for (int j = i; j != src; j = path[j]) {
            vertices.push_back(j);
        }

        cout << src;
        for (int j = vertices.size() - 1; j >= 0; --j) {
            cout << " -> " << vertices[j];
        }
        cout << endl;
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
            graph[b].push_back(make_pair(a, w));
        }

        cout << "Type the source: ";
        cin >> a;

        dijkstra_path(graph, a, n);
    }
    return(0);
}
