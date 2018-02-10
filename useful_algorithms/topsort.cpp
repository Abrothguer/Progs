// Graphs - Topological Sort

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stdlib.h>

using namespace std;

int* find_indegree(vector <int> graph[], int n){
    // Starts the in degree of all vertices as 0.
    int* indegree = (int *) malloc(sizeof(int)*n);

    for(int i=0; i<n; ++i){
        indegree[i] = 0;
    }

    // Finds the in degree of all vertices.
    for(int i=0; i<n; ++i){
        for(unsigned j=0; j<graph[i].size(); ++j){
            indegree[ graph[i][j] ]++;
        }
    }

    return indegree;
}


// Basic topological sort, takes a graph and the number of vertices.
// Uses stl queue.
void topsort(vector<int> graph[], int n){

    // Puts vertices with in degree equal to 0 in a queue.
    queue <int> sortqu;
    bool seen[n];
    int* indegree = find_indegree(graph, n);

    for(int i=0; i<n; ++i){
        if(not indegree[i]){
            sortqu.push(i);
        }
        seen[i] = 0;
    }

    // Sorts the graph.
    int cur, nxt, count = 0;
    while(not sortqu.empty()){

        count++;
        cur = sortqu.front();
        sortqu.pop();
        cout << cur << " -> ";

        for(unsigned i=0; i<graph[cur].size(); ++i){
            nxt = graph[cur][i];
            indegree[nxt]--;

            if(!seen[nxt] and !indegree[nxt]){
                sortqu.push(nxt);
            }
        }
    }

    free(indegree);
    cout << endl;
}


// The result of the topological sort is given based on the input
// Uses stl list.
void topsort_ordered(vector<int> graph[], int n){

    // Puts the vertices on the list
    list <int> vertices;
    bool seen[n];
    int* indegree = find_indegree(graph, n);

    for(int i=0; i<n; ++i){
        vertices.push_back(i);
        seen[i] = 0;
    }

    // Sorts the list
    list <int> :: iterator it;

    while(not vertices.empty()){

        for(it=vertices.begin(); it!=vertices.end(); ++it){

            if(not seen[*it] and not indegree[*it]){
                seen[*it] = true;
                cout << *it << " => ";
                for(unsigned i=0; i<graph[*it].size(); ++i){

                    indegree[ graph[*it][i] ]--;
                }
                vertices.erase(it);
                break;
            }
        }
    }
    cout << endl;
    free(indegree);
}
