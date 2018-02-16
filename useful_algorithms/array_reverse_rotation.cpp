#include <iostream>

using namespace std;

void reverse_array(int array[], int s, int n) {
    n -= 1;
    while (s < n) {
        array[s] ^= array[n];
        array[n] ^= array[s];
        array[s] ^= array[n];
        s++;
        n--;
    }
}

void reverse_rotation(int array[], int n, int r) {
    reverse_array(array, 0, r);
    reverse_array(array, r, n);
    reverse_array(array, 0, n);
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
        reverse_rotation(array, n, r);
        for (int i = 0; i < n; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    return(0);
}
