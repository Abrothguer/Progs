#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void simple_dfs(vector <int> graph[], int vertex, bool seen[], stack <int> &finished){

    int next;
    seen[vertex] = true;

    // Explores the children
    for(unsigned i=0; i<graph[vertex].size(); ++i){

        next = graph[vertex][i];
        if(not seen[next]){
            simple_dfs(graph, next, seen, finished);
        }
    }

    // All children explored
    finished.push(vertex);
}

void find_ssc(vector <int> graph[], int vertex, bool seen[], vector <int> &component){

    int next;
    seen[vertex] = true;
    component.push_back(vertex);

    // Just explores.
    for(unsigned i=0; i<graph[vertex].size(); ++i){

        next = graph[vertex][i];
        if(not seen[next]){
            find_ssc(graph, next, seen, component);
        }
    }
}

int main(){
    int n, e;

    while(true){

        cout << "Nro of vertices: ";
        cin >> n;
        if(not n) break;
        cout << "Nro of edges: ";
        cin >> e;
        cout << "Type the edges " << endl;

        vector <int> graph[n];
        vector <int> transpose[n];
        stack <int> finished;
        int a, b, node;

        for(int i=0; i<e; ++i){
            cin >> a >> b;
            graph[a].push_back(b);
            transpose[b].push_back(a);
        }

        bool seen[n];
        for(int i=0; i<n; ++i) seen[i] = false;

        for(int i=0; i<n; ++i){
            if(not seen[i]){
                simple_dfs(graph, i, seen, finished);
            }
        }

        for(int i=0; i<n; ++i) seen[i] = false;
        vector < vector<int> > all_components;

        while(not finished.empty()){
            node = finished.top();
            finished.pop();

            if(not seen[node]){
                vector <int> component;
                find_ssc(transpose, node, seen, component);
                all_components.push_back(component);
            }
        }

        cout << "Strongly Connected Components: " << endl;
        for(unsigned i=0; i<all_components.size(); ++i){
            cout << "(";
            for(unsigned j=0; j<all_components[i].size(); ++j){
                cout << (j == 0 ? " " : " - ") << all_components[i][j];
            }
            cout << " )" << endl;
        }
    }

    return 0;
}
