#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a == 0) {
        return(b);
    }
    else{ return(gcd(b % a, a)); }
}

void juggle(int array[], int n, int r) {
    int sets = gcd(n, r);
    int current, next, aux;

    for (int i = 0; i < sets; ++i) {
        aux     = array[i];
        current = i;
        for (next = (current + r) % n; next != i; next = (next + r) % n) {
            array[current] = array[next];
            current        = next;
        }
        array[current] = aux;
    }
}

int main() {
    int n, a, r;

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

        cout << "Rotate array by: " << endl;
        cin >> r;

        cout << "Your rotated array: " << endl;
        juggle(array, n, r);
        for (int i = 0; i < n; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    return(0);
}
