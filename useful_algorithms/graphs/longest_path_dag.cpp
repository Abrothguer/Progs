// Finds longest path on a directed acyclic graph.

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// Topological sort of the graph.
vector <int> top_sort(vector <pair <int, int> > graph[], int n, int indegree[]) {
    vector <int> nodes;
    queue <int>  qusort;
    int          node, vertex;

    for (int i = 0; i < n; ++i) {
        if (not indegree[i]) {
            qusort.push(i);
        }
    }

    while (not qusort.empty()) {
        node = qusort.front();
        qusort.pop();
        nodes.push_back(node);

        for (unsigned i = 0; i < graph[node].size(); ++i) {
            vertex = graph[node][i].first;
            indegree[vertex]--;

            if (not indegree[vertex]) {
                qusort.push(vertex);
            }
        }
    }

    return(nodes);
}

void find_longest(int source, vector <pair <int, int> > graph[], int distance[], vector <int> nodes_sorted) {
    int node, vertex;

    distance[source] = 0;

    for (unsigned i = 0; i < nodes_sorted.size(); ++i) {
        node = nodes_sorted[i];

        for (unsigned j = 0; j < graph[node].size(); ++j) {
            vertex = graph[node][j].first;

            if (distance[vertex] < distance[node] + graph[node][j].second) {
                distance[vertex] = distance[node] + graph[node][j].second;
            }
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
        int indegree[n], distance[n];
        vector <pair <int, int> > graph[n];

        for (int i = 0; i < n; ++i) {
            indegree[i] = 0;
            distance[i] = INT_MIN;
        }

        for (int i = 0; i < e; ++i) {
            cin >> a >> b >> w;
            graph[a].push_back(make_pair(b, w));
            indegree[b]++;
        }

        vector <int> nodes_sorted = top_sort(graph, n, indegree);
        cout << " TOP SORT IS " << endl;
        for (int i = 0; i < n; ++i) {
            cout << " " << nodes_sorted[i];
        }

        cout << "Type the source node: ";
        cin >> a;

        find_longest(a, graph, distance, nodes_sorted);

        cout << "The longest distances are: " << endl;

        for (int i = 0; i < n; ++i) {
            cout << "Longes between " << i << " and " << a << " is " << distance[i] << endl;
        }
    }
}
