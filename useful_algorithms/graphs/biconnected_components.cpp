#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;


int *parent;
int *lowest_time;
int *visited_time;

void biconnected_components(vector<int> graph[], int vertex, stack <pair<int, int> > &edges, int &tm){
    lowest_time[vertex]  = tm;
    visited_time[vertex] = tm;
    ++tm;

    int children = 0, descendant;

    for (unsigned i = 0; i < graph[vertex].size(); ++i) {
        descendant = graph[vertex][i];

        if (not visited_time[descendant]) {
            ++children;
            parent[descendant] = vertex;
            edges.push(make_pair(vertex, descendant) );
            biconnected_components(graph, descendant, edges, tm);

            lowest_time[vertex] = min(lowest_time[vertex], lowest_time[descendant]);

            if ( (parent[vertex] == -1 and children >= 2)or
                     (parent[vertex] != -1 and visited_time[vertex] <= lowest_time[descendant]) ) {
                while (edges.top().first != vertex or edges.top().second != descendant) {
                    cout << edges.top().first << "-" << edges.top().second << "; ";
                    edges.pop();
                }
                cout << vertex << "-" << descendant << ";" << endl;
                edges.pop();
            }
        }
        else if (parent[vertex] != descendant and visited_time[descendant] < visited_time[vertex]) {
            lowest_time[vertex] = min(lowest_time[vertex], visited_time[descendant]);
            edges.push(make_pair(vertex, descendant) );
        }
    }
}

void find_bc(vector<int> graph[], int n){
    parent       = (int *) calloc(n, sizeof(int) );
    lowest_time  = (int *) calloc(n, sizeof(int) );
    visited_time = (int *) calloc(n, sizeof(int) );

    stack < pair<int, int> > edges_added;

    for (int i = 0; i < n; ++i) {
        if (not visited_time[i]) {
            int t = 1;
            parent[i] = -1;
            biconnected_components(graph, i, edges_added, t);

            while (not edges_added.empty() ) {
                cout << edges_added.top().first << "-" << edges_added.top().second << "; ";
                edges_added.pop();
            }
            cout << endl;
        }
    }
    free(parent);
    free(lowest_time);
    free(visited_time);
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

        cout << "Type the edges: " << endl;
        vector <int> graph[n];
        int          a, b;

        for (int i = 0; i < e; ++i) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        find_bc(graph, n);
    }
    return (0);
}
