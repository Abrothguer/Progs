#include <iostream>
#include <map>
#include <stdlib.h>

using namespace std;

struct Node{
    int data;
    int rank;
    Node *parent;
};

Node* make_set(int data){
    Node *n = (Node *) malloc(sizeof(Node));

    n->data = data;
    n->rank = 0;
    n->parent = n;

    return n;
}


Node* find_set(Node *n){
    if(n->parent == n) return n->parent;

    n->parent = find_set(n->parent);
    return n->parent;
}


void union_set(Node *n1, Node *n2){

    Node *p1 = find_set(n1);
    Node *p2 = find_set(n2);

    if(p1 == p2) return;

    if(p1->rank == p2->rank or p1->rank > p2->rank){
        p2->parent = p1;
        p1->rank = p1->rank == p2->rank ? p1->rank+1 : p1->rank;
    }
    else{
        p1->parent = p2;
    }
}

int main(){
    int n, o, a, b;
    while(true){

        cout << "How many sets? ";
        cin >> n;
        if(not n) break;

        map < int, Node* > nodedict;

        for(int i=0; i<n; ++i){
            nodedict[i] = make_set(i);
        }

        while(true){
            cout << "1. Find, 2. Union, 3. Break : ";
            cin >> o;

            if(o == 2){
                cin >> a >> b;
                union_set(nodedict[a], nodedict[b]);
            }
            else if(o == 1){
                cin >> a;
                cout << "Set of " << a << " is " << find_set(nodedict[a])->data << endl;
            }
            else break;
        }
    }
    return 0;
}
