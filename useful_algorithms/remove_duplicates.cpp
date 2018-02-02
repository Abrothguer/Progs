#include <iostream>

using namespace std;

int remove_duplicates(int arr[], int n){
    int pos, prev;
    prev = arr[0];
    for(int i=pos=1; i<n; ++i){
        if(arr[i] != prev){
            arr[pos++] = arr[i];
        }
        prev = arr[i];
    }
    return pos;
}

int main(){
    int n, p;
    cout << "Size of array?: ";
    cin >> n;
    int arr[n];
    cout << "Type your array: ";
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
    p = remove_duplicates(arr,n);
    cout << "Your array: " << endl;
    for(int i=0; i<p; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}