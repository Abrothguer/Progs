#include <iostream>

using namespace std;

int lis(int array[], int n) {
    int maxlen = 1;
    int longest[n];

    for (int i = 0; i < n; ++i) {
        longest[i] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (array[j] < array[i]) {
                longest[i] = max(longest[j] + 1, longest[i]);
                maxlen     = max(maxlen, longest[i]);
            }
        }
    }
    return(maxlen);
}

int main() {
    int n;

    while (true) {
        cout << "Type the size of the array: ";
        cin >> n;
        if (n <= 0) {
            break;
        }
        int array[n];
        cout << "Type the elements: " << endl;

        for (int i = 0; i < n; ++i) {
            cin >> array[i];
        }
        cout << "The lenght of the Longest Increasing Subsequence is " << lis(array, n) << endl;
    }
}
