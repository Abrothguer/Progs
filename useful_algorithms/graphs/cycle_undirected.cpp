// Detects a cycle in a undirected graph.

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int find_set(int parent[], int a){
    if(parent[a] == a) return a;
    parent[a] = find_set(parent, parent[a]);
    return parent[a];
}

void union_set(int parent[], int a, int b){
    int pa, pb;

    pa = find_set(parent, a);
    pb = find_set(parent, b);

    if(pa == pb) return;
    parent[pa] = pb;
}


bool find_cycle(vector <int> graph[], vector < pair < int, int > > edges, int n){

    int a, b;
    int parent[n];
    for(int i=0; i<n; ++i) parent[i] = i;

    for(unsigned i=0; i<edges.size(); ++i){

        a = edges[i].first;
        b = edges[i].second;

        if(find_set(parent, a) == find_set(parent, b)) return true;

        union_set(parent, a, b);
    }
    return false;
}


int main(){
    int n, e;

    while(true){

        cout << "Nro of vertices: ";
        cin >> n;
        if(not n) break;
        cout << "Nro of edges: ";
        cin >> e;

        vector <int> graph[n];
        vector < pair < int, int > > edges;
        int a, b;

        for(int i=0; i<e; ++i){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            edges.push_back( make_pair(a,b) );
        }

        if(find_cycle(graph, edges, n)) cout << "There is a cycle in your graph!" << endl;
        else cout << "Your graph has no cycle" << endl;

    }
    return 0;
}
