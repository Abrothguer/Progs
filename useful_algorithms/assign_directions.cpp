#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

void assign(vector <int> graph[], int n, vector <pair <int, int> > unassigned, int indegree[]) {
    queue <int>    qusort;
    map <int, int> dict;
    vector <int>   sorted;

    for (int i = 0; i < n; ++i) {
        if (not indegree[i]) {
            qusort.push(i);
        }
    }

    // Finds the topological sort of the graph.
    int node, index = 0;
    while (not qusort.empty()) {
        node = qusort.front();
        qusort.pop();

        if (index and dict[node]) {
            continue;
        }
        dict[node] = index++;
        sorted.push_back(node);

        for (unsigned i = 0; i < graph[node].size(); ++i) {
            indegree[graph[node][i]]--;
            if (not indegree[graph[node][i]]) {
                qusort.push(graph[node][i]);
            }
        }
    }
    cout << endl;
    int v1, v2;
    for (unsigned i = 0; i < unassigned.size(); ++i) {
        v1 = unassigned[i].first;
        v2 = unassigned[i].second;

        if (dict[v1] < dict[v2]) {
            cout << "Assign edge " << v1 << " -> " << v2 << " to remain acyclic" << endl;
        }
        else{
            cout << "Assign edge " << v2 << " -> " << v1 << " to remain acyclic" << endl;
        }
    }
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
        int          indegree[n];

        for (int i = 0; i < n; ++i) {
            indegree[i] = 0;
        }

        for (int i = 0; i < e; ++i) {
            cin >> a >> b;
            graph[a].push_back(b);
            indegree[b]++;
        }

        cout << "Unassigned edges: ";
        cin >> e;
        vector <pair <int, int> > unassigned;

        for (int i = 0; i < e; ++i) {
            cin >> a >> b;
            unassigned.push_back(make_pair(a, b));
        }
        assign(graph, n, unassigned, indegree);
        return(0);
    }
}
