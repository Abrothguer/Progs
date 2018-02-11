#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>

using namespace std;

set <int> articulation_pts;
int *parent;
int *visited;
int *lowest_time;
int *visited_time;

void find_articulation(vector<int> graph[], int node, int t){

    // First visit to the node, seting variables of lowest time, visited time
    // and marking it as visited.
    visited[node] = 1;
    lowest_time[node] = t;
    visited_time[node] = t;

    int descendant, children = 0;
    for(unsigned i=0; i<graph[node].size(); ++i){

        // If the descendant is also the parent ignore it.
        descendant = graph[node][i];
        if(descendant == parent[node]) continue;

        // If the descendant has not been visited yet.
        if(not visited[descendant]){

            // Make the current node parent of the descendant and add
            // one to node's children variable.
            parent[descendant] = node;
            children++;

            // Calls the recursion for de descendant, setting its lowest time
            // and visited time variables
            find_articulation(graph, descendant, t+1);

            // If the lowest time of the node is less than or equal to the lowest
            // time of its descendant, then the node is a articulation point,
            // meaning that there is no back edges ahead.
            if(lowest_time[node] <= lowest_time[descendant] and parent[node] != -1){
                articulation_pts.insert(node);
            }
            lowest_time[node] = min(lowest_time[node], lowest_time[descendant]);
        }
        // If the descendant has already been visited it means that this edge
        // is a back edge, and so we take the update the lowest time to arrive
        // at the node based on the lowest time of its descendant.
        else{
            lowest_time[node] = min(lowest_time[node], lowest_time[descendant]);
        }
    }

    // Special case for the root of dfs, if it has two independent children
    // than the root is a articulation point.
    if(parent[node] == -1 and children >= 2){
        articulation_pts.insert(node);
    }
}


int main(){
    int n, e;

    while(true){

        cout << "Nro of vertices: ";
        cin >> n;
        cout << "Nro of edges: ";
        cin >> e;

        if(not n) break;
        vector <int> graph[n];
        int a, b;

        for(int i=0; i< e; ++i){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        parent = (int *) calloc(n, sizeof(int));
        visited = (int *) calloc(n, sizeof(int));
        lowest_time = (int *) calloc(n, sizeof(int));
        visited_time = (int *) calloc(n, sizeof(int));

        parent[0] = -1;
        articulation_pts.clear();
        find_articulation(graph, 0, 0);
        cout << "Articulation points in your graph: " << endl;
        set <int> :: iterator it;

        for(it=articulation_pts.begin(); it!=articulation_pts.end(); ++it){
            cout << *it << endl;
        }

        free(parent);
        free(visited);
        free(lowest_time);
        free(visited_time);
    }
}
