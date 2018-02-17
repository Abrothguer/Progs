// Checks if a graph is biconnected or not.

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int *parent;
int *visited;
int *lowest_time;
int *visited_time;

// Code to find an articulation point in the graph

bool has_arc_point(vector<int> graph[], int current, int tm){
    visited[current]      = true;
    lowest_time[current]  = tm;
    visited_time[current] = tm;

    int descendant, children = 0;
    for (unsigned i = 0; i < graph[current].size(); ++i) {
        descendant = graph[current][i];
        if (descendant == parent[current]) {
            continue;
        }

        if (not visited[descendant]) {
            ++children;
            parent[descendant] = current;

            if (has_arc_point(graph, descendant, tm + 1) ) {
                return (true);
            }
            lowest_time[current] = min(lowest_time[current], lowest_time[descendant]);

            if (visited_time[current] <= lowest_time[descendant] and parent[current] != -1) {
                return (true);
            }
        }
        else {
            lowest_time[current] = min(lowest_time[current], visited_time[descendant]);
        }
    }
    if (parent[current] == -1 and children >= 2) {
        return (true);
    }

    return (false);
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

        vector <int> graph[n];
        int          a, b;
        bool         bicon;

        cout << "Type the edges: " << endl;
        for (int i = 0; i < e; ++i) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        parent       = (int *) calloc(n, sizeof(int) );
        visited      = (int *) calloc(n, sizeof(int) );
        lowest_time  = (int *) calloc(n, sizeof(int) );
        visited_time = (int *) calloc(n, sizeof(int) );

        parent[0] = -1;

        // If the graph has an articulation point then it is not biconnected.
        if (has_arc_point(graph, 0, 0) ) {
            cout << "Your graph is not biconnected because it has a articulation point" << endl;
            continue;
        }
        bicon = true;

        // If the graph is not connected then it is not biconnected - duh.
        for (int i = 0; i < n; ++i) {
            if (not visited[i]) {
                bicon = false;
                break;
            }
        }

        if (bicon) {
            cout << "Your graph is biconnected" << endl;
        }
        else{
            cout << "Your graph is not biconnected" << endl;
        }

        free(parent);
        free(visited);
        free(lowest_time);
        free(visited_time);
    }
}
