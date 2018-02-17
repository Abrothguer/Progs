#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<int> graph[], int vertex, bool seen[], stack <int> &finished){
    seen[vertex] = true;

    for (unsigned i = 0; i < graph[vertex].size(); ++i) {
        if (not seen[ graph[vertex][i] ]) {
            dfs(graph, graph[vertex][i], seen, finished);
        }
    }

    finished.push(vertex);
}

int main(){
    int  n, e, a, b;
    bool ssc;
    while (true) {
        cout << "Nro of vertices: ";
        cin >> n;
        if (not n) {
            break;
        }
        cout << "Nro of edges: ";
        cin >> e;

        vector <int> graph[n];
        vector <int> transpose[n];

        cout << "Type the edges: " << endl;
        for (int i = 0; i < e; ++i) {
            cin >> a >> b;
            graph[a].push_back(b);
            transpose[b].push_back(a);
        }

        stack <int> finished;
        bool        seen[n];
        for (int i = 0; i < n; ++i) {
            seen[i] = false;
        }

        dfs(graph, 0, seen, finished);

        // If the dfs did not reach all vertices then the graph is not strongly connected.
        if (finished.size() != (unsigned) n) {
            cout << "Your graph is not strongly connected" << endl;
            continue;
        }

        for (int i = 0; i < n; ++i) {
            seen[i] = false;
        }
        dfs(transpose, finished.top(), seen, finished);
        ssc = true;
        for (int i = 0; i < n; ++i) {
            if (not seen[i]) {
                ssc = false;
                break;
            }
        }

        if (ssc) {
            cout << "Your graph is strongly connected" << endl;
        }
        else{
            cout << "Your graph is not strongly connected" << endl;
        }
    }
    return (0);
}
