#include <iostream>

using namespace std;

bool subset_bf(int values[], int i, int ac, int n) {
    if (ac == 0) {
        return(true);
    }
    if (ac < 0 or i == n) {
        return(false);
    }

    if (subset_bf(values, i + 1, ac, n)) {
        return(true);
    }

    return(subset_bf(values, i + 1, ac - values[i], n));
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

        if (subset_bf(values, 0, s, n)) {
            cout << "There is a subset with sum " << s << endl;
        }
        else{
            cout << "There is no subset with sum " << s << endl;
        }
    }
    return(0);
}
