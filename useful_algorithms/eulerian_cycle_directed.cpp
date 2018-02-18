#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void kosaraju_dfs(vector<int> graph[], int src, bool seen[], stack <int> &finished){
    seen[src] = true;
    for (unsigned i = 0; i < graph[src].size(); ++i) {
        if (not seen[graph[src][i]]) {
            kosaraju_dfs(graph, graph[src][i], seen, finished);
        }
    }

    finished.push(src);
}

void dfs(vector<int> graph[], bool seen[], int vertex){
    seen[vertex] = true;

    for (unsigned i = 0; i < graph[vertex].size(); ++i) {
        if (not seen[graph[vertex][i]]) {
            dfs(graph, seen, graph[vertex][i]);
        }
    }
}

bool eulerian_cycle(vector<int> graph[], vector<int> transpose[], int n, int indegree[]){
    // Checking if indegree and outdegree of every vertex is the same.
    for (int i = 0; i < n; ++i) {
        if (unsigned(indegree[i]) != graph[i].size() ) {
            return (false);
        }
    }

    // Checking if all the vertices with degree different than 0 belong
    // to the same strongly connected component.

    int         vertex;
    bool        seen[n];
    stack <int> finished;

    // Find vertex with degree different than 0.
    for (int i = 0; i < n; ++i) {
        if (indegree[i]) {
            vertex = i;
            break;
        }
    }

    // Run kosaraju dfs on it.
    for (int i = 0; i < n; ++i) {
        seen[i] = false;
    }
    kosaraju_dfs(graph, vertex, seen, finished);

    // Run simple dfs on transpose and checks if every vertex has been visited.
    for (int i = 0; i < n; ++i) {
        seen[i] = false;
    }
    dfs(transpose, seen, finished.top() );

    for (int i = 0; i < n; ++i) {
        if (indegree[i] and not seen[i]) {
            return (false);
        }
    }
    return (true);
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
        vector<int>  transpose[n];
        int          indegree[n];

        cout << "Type the edges: " << endl;
        for (int i = 0; i < n; ++i) {
            indegree[i] = 0;
        }

        for (int i = 0; i < e; ++i) {
            cin >> a >> b;
            graph[a].push_back(b);
            transpose[b].push_back(a);
            indegree[b]++;
        }

        if (eulerian_cycle(graph, transpose, n, indegree) ) {
            cout << "There is an eulerian cycle in your graph" << endl;
        }
        else{
            cout << "There is not an eulerian cycle in your graph" << endl;
        }
    }

    return (0);
}
