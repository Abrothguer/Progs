#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool check_bipartite(vector<int> graph[], int n){

    bool seen[n];
    int colored[n];

    for(int i=0; i<n; ++i){
        seen[i] = false;
        colored[i] = -1;
    }

    for(int i=0; i<n; ++i){

        if(seen[i]) continue;

        queue <int> qubfs;
        qubfs.push(i);

        int vertex;
        while(not qubfs.empty()){

            vertex = qubfs.front();
            qubfs.pop();

            for(unsigned j=0; j<graph[vertex].size(); ++j){

                if(not seen[ graph[vertex][j] ]){
                    colored[ graph[vertex][j] ] = colored[vertex] == 1 ? 0 : 1;
                }
                else if(colored[ graph[vertex][j] ] == colored[vertex]){
                    return false;
                }
            }
        }
    }
    return true;
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
        int a, b;

        for(int i=0; i< e; ++i){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        if(check_bipartite(graph, n)) cout << "Your graph is bipartite" << endl;
        else cout << "Your graph is not bipartite" << endl;
    }

    return 0;
}
