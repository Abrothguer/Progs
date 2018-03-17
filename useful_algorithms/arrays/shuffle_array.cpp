#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void shuffle_array(int array[], int n) {
    int rd;

    srand(time(NULL));

    for (int i = n - 1; i > 0; --i) {
        rd = rand() % (i + 1);
        if (i == rd) {
            continue;
        }
        array[i]  ^= array[rd];
        array[rd] ^= array[i];
        array[i]  ^= array[rd];
    }
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

        cout << "Your shuffled array: " << endl;
        shuffle_array(array, n);
        for (int i = 0; i < n; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    return(0);
}
