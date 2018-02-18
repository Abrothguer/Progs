#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;

bool *in_stack;
bool *visited;
int  *lowest_time;
int  *visited_time;


void tarjan_dfs(vector <int> graph[], int vertex, int &tm, stack <int> &comps){
    int target;
    comps.push(vertex);
    in_stack[vertex]     = true;
    visited[vertex]      = true;
    lowest_time[vertex]  = tm;
    visited_time[vertex] = tm;
    tm++;

    // Explore all the children
    for (unsigned i = 0; i < graph[vertex].size(); ++i) {
        target = graph[vertex][i];

        // If the child has not been visited, explore it and update the lowest time
        // of the current vertex.
        if (not visited_time[target]) {
            tarjan_dfs(graph, target, tm, comps);
            lowest_time[vertex] = min(lowest_time[vertex], lowest_time[target]);
        }
        // Else if the child has already been visited and it is on the stack, this
        // edge is a back-edge, so update the lowest time of the current vertex.
        else if (in_stack[target]) {
            lowest_time[vertex] = min(lowest_time[vertex], visited_time[target]);
        }
    }

    if (lowest_time[vertex] != visited_time[vertex]) {
        return;
    }

    // If the lowest time and the visited time are the same, than this vertex is
    // a head of the dfs subtree, therefore all of its children that remain on the
    // stack are part of a strongly connected component.
    while (comps.top() != vertex) {
        in_stack[comps.top()] = false;
        cout << comps.top() << " ";
        comps.pop();
    }

    in_stack[comps.top()] = false;
    cout << comps.top() << endl;
    comps.pop();
}


void tarjan_ssc(vector <int> graph[], int n){
    in_stack     = (bool *) calloc(n, sizeof(bool) );
    visited      = (bool *) calloc(n, sizeof(bool) );
    lowest_time  = (int *) calloc(n, sizeof(int) );
    visited_time = (int *) calloc(n, sizeof(int) );

    stack<int> vertices;
    int        t;

    cout << "The strongly connected components are: " << endl;
    for (int i = 0; i < n; ++i) {
        if (not visited_time[i]) {
            t = 1;
            tarjan_dfs(graph, i, t, vertices);
        }
    }

    free(in_stack);
    free(visited);
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

        vector <int> graph[n];
        int          a, b;

        cout << "Type the edges: " << endl;
        for (int i = 0; i < e; ++i) {
            cin >> a >> b;
            graph[a].push_back(b);
        }

        tarjan_ssc(graph, n);
    }
}
