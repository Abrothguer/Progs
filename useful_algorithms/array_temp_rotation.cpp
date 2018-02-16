#include <iostream>
#include <stdlib.h>

using namespace std;

int *rotate_array_left(int array[], int n, int rot) {
    if (rot >= n) {
        rot = rot % n;
    }
    if (not rot) {
        return(array);
    }

    int *newarray = (int *) malloc(sizeof(int) * n);

    for (int i = 0, current = rot; i < n; ++i) {
        newarray[i] = array[current];
        current     = current == n - 1 ? 0 : current + 1;
    }
    return(newarray);
}

int *rotate_array_right(int array[], int n, int rot) {
    if (rot >= n) {
        rot = rot % n;
    }
    if (not rot) {
        return(array);
    }

    int *newarray = (int *) malloc(sizeof(int) * n);

    for (int i = 0, current = n - rot; i < n; ++i) {
        newarray[i] = array[current];
        current     = current == n - 1 ? 0 : current + 1;
    }
    return(newarray);
}

int main() {
    int n, a, r;

    while (true) {
        cout << "How many elements: ";
        cin >> n;
        if (not n) {
            break;
        }
        cout << "Type the elements" << endl;

        int array[n];
        for (int i = 0; i < n; ++i) {
            cin >> a;
            array[i] = a;
        }

        cout << "Rotate array by: " << endl;
        cin >> r;

        int *arrleft  = rotate_array_left(array, n, r);
        int *arrright = rotate_array_right(array, n, r);

        cout << "Your left-rotated array: " << endl;
        for (int i = 0; i < n; ++i) {
            cout << arrleft[i] << " ";
        }
        cout << endl;
        cout << "Your right-rotated array: " << endl;
        for (int i = 0; i < n; ++i) {
            cout << arrright[i] << " ";
        }
        cout << endl;
    }
    return(0);
}
