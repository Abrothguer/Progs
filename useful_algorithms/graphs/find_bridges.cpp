#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <stdlib.h>

using namespace std;

set < pair<int, int> > bridges;
int *parent;
int *visited;
int *lowest_time;
int *visited_time;


void find_bridges(vector <int> graph[], int node, int t){

    // First visit to the node, set lowest time, visited time and visited.
    visited[node] = 1;
    visited_time[node] = t;
    lowest_time[node] = t;

    int descendant;
    for(unsigned i=0; i<graph[node].size(); ++i){

        // If descendant is parent node ignore it.
        descendant = graph[node][i];
        if(descendant == parent[node]) continue;

        // If descendant has not been visited yet explore it.
        if(not visited[descendant]){

            parent[descendant] = node;
            find_bridges(graph, descendant, t+1);
            lowest_time[node] = min(lowest_time[node], lowest_time[descendant]);
            
            if(visited_time[node] < lowest_time[descendant]){
                bridges.insert(make_pair(node, descendant));
            }
        }

        // If descendant has been visited, update the lowest time
        else{
            lowest_time[node] = min(lowest_time[node], visited_time[descendant]);
        }
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
        bridges.clear();
        find_bridges(graph, 0, 0);
        cout << "Bridge edges in your graph: " << endl;
        set < pair<int,int> > :: iterator it;

        for(it=bridges.begin(); it!=bridges.end(); ++it){
            cout << "(" << (*it).first << ", " << (*it).second << ")" << endl;
        }

        free(parent);
        free(visited);
        free(lowest_time);
        free(visited_time);
    }
}
