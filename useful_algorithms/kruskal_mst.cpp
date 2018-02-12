#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

// Finds a set.
int find_set(int parent[], int data){
    if(parent[data] == data) return data;

    parent[data] = find_set(parent, parent[data]);
    return parent[data];
}

// Unite two different sets.
void union_set(int parent[], int a, int b){

    int p1, p2;
    p1 = find_set(parent, a);
    p2 = find_set(parent, b);

    if(p1 == p2) return;

    parent[p1] = p2;
    return;
}

// Returns the edges.
vector<pair<int,pair<int,int> > > kruskal_edges(vector<pair<int,int> > graph[], vector<pair<int,pair<int,int> > > edges, int n){

    vector < pair < int, pair < int, int > > > tree_edges;

    // Sets the parent for the disjoint sets;
    int parent[n], a, b, w;
    for(int i=0; i<n; ++i) parent[i] = i;

    // Sorting the edges.
    sort(edges.begin(), edges.end());

    for(unsigned i=0; i<edges.size(); ++i){

        a = edges[i].second.first;
        b = edges[i].second.second;
        w = edges[i].first;

        // If nodes are on the same set ignore the edge.
        if(find_set(parent, a) == find_set(parent, b)) continue;

        // If not, put the edge on the tree edges and join
        // the different sets of a and b.
        union_set(parent, a, b);
        tree_edges.push_back( make_pair(w, make_pair(a, b)) );
    }

    return tree_edges;
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
       vector < pair < int , pair < int, int > > > edges;

       for(int i=0; i<e; ++i){
           cin >> a >> b >> w;
           graph[a].push_back( make_pair(b, w) );
           graph[b].push_back( make_pair(a, w) );
           edges.push_back( make_pair( w, make_pair(a, b) ) );
       }

       vector < pair < int, pair < int, int > > > mst_edges;
       mst_edges = kruskal_edges(graph, edges, n);

       cout << "The selecte edges for the Minimum Spanning Tree are: " << endl;
       for(unsigned i=0; i<mst_edges.size(); ++i){
           cout << "( " << mst_edges[i].second.first << ", " << mst_edges[i].second.second << " ) with weight " << mst_edges[i].first << endl;
       }
   }
    return 0;
}
