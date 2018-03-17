#include <iostream>
#include <vector>
#include <limits.h>
#include <stdlib.h>
#include <queue>
#include <iomanip>

using namespace std;

int *bellman_ford(vector <pair <int, pair <int, int> > > edges, int n, int src) {
    int  v1, v2, w;
    int *distance = (int * ) malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i) {
        distance[i] = INT_MAX;
    }
    distance[src] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (unsigned j = 0; j < edges.size(); ++j) {
            v1 = edges[j].second.first;
            v2 = edges[j].second.second;
            w  = edges[j].first;

            if (distance[v1] == INT_MAX) {
                continue;
            }
            if (distance[v2] > distance[v1] + w) {
                distance[v2] = distance[v1] + w;
            }
        }
    }

    return(distance);
}

int *dijkstra(vector <pair <int, int> > graph[], int src, int n) {
    int *distance = (int *) malloc(sizeof(int) * n);
    int  seen[n];

    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
    int vertex, weight, node;

    for (int i = 0; i < n; ++i) {
        distance[i] = INT_MAX;
        seen[i]     = false;
    }
    distance[src] = 0;
    pq.push(make_pair(0, src));

    while (not pq.empty()) {
        vertex = pq.top().second;
        pq.pop();
        if (seen[vertex]) {
            continue;
        }
        seen[vertex] = true;

        for (unsigned i = 0; i < graph[vertex].size(); ++i) {
            node   = graph[vertex][i].first;
            weight = graph[vertex][i].second;

            if (distance[node] > weight + distance[vertex]) {
                distance[node] = weight + distance[vertex];
                pq.push(make_pair(distance[node], node));
            }
        }
    }
    return(distance);
}

void johnson_apsp(vector <pair <int, int> > graph[], vector <pair <int, pair <int, int> > > edges, int n) {
    // Adds a new vertex to the graph and edges with weight equal to 0 that
    // connects it to every other vertex.
    for (int i = 0; i <= n; ++i) {
        graph[n].push_back(make_pair(i, 0));
        edges.push_back(make_pair(0, make_pair(n, i)));
    }

    // Calculates the shortest path to all vertices starting at vertex n.
    int *distances = bellman_ford(edges, n + 1, n);

    // Reweight all the edges in the graph using the calculated distance.
    int v1, v2;
    for (unsigned i = 0; i < edges.size(); ++i) {
        v1             = edges[i].second.first;
        v2             = edges[i].second.second;
        edges[i].first = edges[i].first + distances[v1] - distances[v2];
    }

    // Runs dijkstra an obscene amount of times to find all shortest distances.
    int **apsp_matrix = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i) {
        apsp_matrix[i] = dijkstra(graph, i, n);
    }

    // Finally done - just print it;
    cout << "The all-pairs shortest path matrix is: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (apsp_matrix[i][j] == INT_MAX) {
                cout << setw(5) << "INF";
            }
            else{ cout << setw(5) << apsp_matrix[i][j]; }
        }
        cout << endl;
    }
}

int main() {
    int n, e, a, b, w;

    while (true) {
        cout << "Nro of vertices: ";
        cin >> n;
        if (not n) {
            break;
        }
        cout << "Nro of edges: ";
        cin >> e;

        vector <pair <int, int> > graph[n + 1];
        vector <pair <int, pair <int, int> > > edges;

        for (int i = 0; i < e; ++i) {
            cin >> a >> b >> w;
            graph[a].push_back(make_pair(b, w));
            edges.push_back(make_pair(w, make_pair(a, b)));
        }
        johnson_apsp(graph, edges, n);
    }

    return(0);
}
