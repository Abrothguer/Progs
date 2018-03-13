#include <iostream>

using namespace std;

int subset_sum(int values[], int sum, int n) {
    int table[n + 1][sum + 1];

    // An empty set {} is always possible!
    for (int i = 0; i <= n; ++i) {
        table[i][0] = 1;
    }
    // A empty set {} cannot produce any sum > 0!
    for (int i = 1; i <= sum; ++i) {
        table[0][i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            // All of the old ways.
            table[i][j] = table[i - 1][j];
            if (values[i - 1] <= j) {
                //Plus a new way, if it exists ;)
                if (table[i - 1][j - values[i - 1]] or(not (j - values[i - 1]))) {
                    table[i][j] += table[i - 1][j - values[i - 1]];
                }
            }
        }
    }

    return(table[n][sum]);
}

int main() {
    int n, s;

    while (true) {
        cout << "Type the size of the array: ";
        cin >> n;
        if (n <= 0) {
            break;
        }

        int values[n];
        cout << "Type the elements of the array: " << endl;
        for (int i = 0; i < n; ++i) {
            cin >> values[i];
        }

        cout << "Type the query sum: ";
        cin >> s;

        cout << "There are " << subset_sum(values, s, n)
             << " subsets with sum equal to " << s << endl;
    }
    return(0);
}
