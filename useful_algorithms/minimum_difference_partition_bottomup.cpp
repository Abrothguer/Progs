#include <iostream>
#include <vector>

using namespace std;

int part_difference(int array[], int n, int sum) {
    int  mini;
    bool table[n + 1][sum + 1];

    // With no values you cant reach any value expect for zero.
    for (int i = 1; i <= sum; ++i) {
        table[0][i] = false;
    }
    // A sum of 0 for a subset is always possible.
    for (int i = 0; i <= n; ++i) {
        table[i][0] = true;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            // See if it's possible to have j without array[i-1] in the subset.
            table[i][j] = table[i - 1][j];

            // See if it's possible to have j including array[i-1] in the subset.
            if (array[i - 1] <= j) {
                table[i][j] = table[i - 1][j - array[i - 1]] | table[i][j];
            }
        }
    }

    // Start from the middle and go back to find the minimum.
    mini = sum;
    for (int i = sum / 2; i >= 0; ++i) {
        if (table[n][i]) {
            mini = sum - 2 * i;
            break;
        }
    }

    return(mini);
}

int main() {
    int n, sum;

    while (true) {
        cout << "How many elements: ";
        cin >> n;
        if (n <= 0) {
            break;
        }

        int array[n];
        sum = 0;

        cout << "Type the elements: " << endl;
        for (int i = 0; i < n; ++i) {
            cin >> array[i];
            sum += array[i];
        }

        cout << "The minimum difference is : " << part_difference(array, n, sum) << endl;
    }
    return(0);
}
