#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector < pair < int, pair < int, int > > > prims_mst(vector < pair < int, int > > graph[], int n){

    // Heap structure -> weigth of the edge has the priority.
    priority_queue < pair< int, int >, vector< pair<int,int> > ,greater <pair<int, int> > > heap;
    vector < pair < int, pair < int, int > > > prim_edges;

    // Parent -> holds the parents for each node, cost -> holds the mininum cost.
    int node, target, weight;
    int parent[n], cost[n];
    bool visited[n];

    for(int i=0; i<n; ++i) parent[i] = -1, visited[i] = false, cost[i] = INT_MAX;

    cost[0] = 0;
    heap.push(make_pair(-1, 0));

    while(not heap.empty()){

        // Pops the element
        node = heap.top().second;
        weight = heap.top().first;
        heap.pop();

        // If the node has not been visited we found an edge that is part of the mst.
        if(visited[node]) continue;
        cost[node] = weight;
        prim_edges.push_back( make_pair(weight, make_pair(parent[node], node) ) );
        visited[node] = true;

        // Explores the children of the node.
        for(unsigned i=0; i<graph[node].size(); ++i){

            target = graph[node][i].first;
            weight = graph[node][i].second;

            if(visited[target]) continue;

            // If the weight of the edge is lesser than the current weight stored for the target
            // Updates the cost and the parent of the target node, and put it in the heap.
            if(weight < cost[target]){
                cost[target] = weight;
                parent[target] = node;
                heap.push(make_pair(weight, target));
            }

        }
    }
    return prim_edges;
}

int main(){
    int n, e;

   while(true){

       cout << "Nro of vertices: ";
       cin >> n;
       if(not n) break;
       cout << "Nro of edges: ";
       cin >> e;
       cout << "Type the edges and weight:" << endl;

       int a, b, w;
       vector < pair < int, int > > graph[n];

       for(int i=0; i<e; ++i){
           cin >> a >> b >> w;
           graph[a].push_back( make_pair(b, w) );
           graph[b].push_back( make_pair(a, w) );
       }

       vector < pair < int, pair < int, int > > > mst;
       mst = prims_mst(graph, n);

       cout << "Edges on the Mininum Spanning Tree " << endl;
       for(unsigned i=0; i<mst.size(); ++i){

           cout << "( " << mst[i].second.first << ", " << mst[i].second.second << " ) with weight = " << mst[i].first << endl;
       }
   }

   return 0;
}
