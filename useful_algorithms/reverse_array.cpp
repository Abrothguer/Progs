#include <iostream>

using namespace std;

void reverse_array(int array[], int n) {
    for (int i = 0; i < n / 2; ++i) {
        array[i]         ^= array[n - i - 1];
        array[n - i - 1] ^= array[i];
        array[i]         ^= array[n - i - 1];
    }
}

void recursive_reverse(int array[], int start, int end) {
    if (start >= end) {
        return;
    }

    array[start] ^= array[end];
    array[end]   ^= array[start];
    array[start] ^= array[end];

    recursive_reverse(array, start + 1, end - 1);
}

int main() {
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

        cout << "Your reversed array: " << endl;
        reverse_array(array, n);
        for (int i = 0; i < n; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    return(0);
}
