#include <iostream>
#include <algorithm>

using namespace std;

void sortwave(int array[], int n){
    for (int i = 0; i < n; i += 2) {
        if (i != 0 and array[i] < array[i - 1]) {
            swap(array[i], array[i - 1]);
        }
        if (i != n - 1 and array[i] < array[i + 1]) {
            swap(array[i], array[i + 1]);
        }
    }
}


int main(){
    int n, a;

    while (true) {
        cout << "How many elements: ";
        cin >> n;
        if (not n) {
            break;
        }
        cout << "Type the elements: " << endl;

        int array[n];
        for (int i = 0; i < n; ++i) {
            cin >> a;
            array[i] = a;
        }

        sortwave(array, n);

        cout << "Your array sorted in wave: " << endl;
        for (int i = 0; i < n; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    return (0);
}
