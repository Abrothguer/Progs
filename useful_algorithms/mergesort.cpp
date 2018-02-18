#include <iostream>

using namespace std;

void mergesort(int array[], int size){
    if (size == 1) {
        return;
    }

    int middle, i, j;
    middle = size / 2;

    int left[middle], right[size - middle];

    for (int i = 0; i < middle; ++i) {
        left[i] = array[i];
    }
    for (int i = 0; i < size - middle; ++i) {
        right[i] = array[middle + i];
    }

    mergesort(left, middle);
    mergesort(right, size - middle);

    i = j = 0;
    for (int k = 0; k < size; ++k) {
        if (i >= middle) {
            array[k] = right[j++];
        }
        else if (j >= size - middle) {
            array[k] = left[i++];
        }
        else if (left[i] < right[j]) {
            array[k] = left[i++];
        }
        else{
            array[k] = right[j++];
        }
    }
}

int main() {
    int n;

    while (true) {
        cout << "How many elements: ";
        cin >> n;
        if (not n) {
            break;
        }
        cout << "Type the elements: " << endl;

        int array[n];
        for (int i = 0; i < n; ++i) {
            cin >> array[i];
        }

        mergesort(array, n);

        cout << "Your sorted array: " << endl;
        for (int i = 0; i < n; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    return (0);
}
