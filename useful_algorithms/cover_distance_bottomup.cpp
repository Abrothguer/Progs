#include <iostream>

using namespace std;

int cover_distance(int n) {
    int table[n + 1];

    table[0] = 1;
    for (int i = 1; i <= n; ++i) {
        table[i] = 0;
        for (int j = 0; j < i; ++j) {
            table[i] += table[j];
        }
    }
    return(table[n]);
}

int main() {
    int n;

    while (true) {
        cout << "Type the distance: ";
        cin >> n;
        if (n < 0) {
            break;
        }

        cout << "There are " << cover_distance(n) << " to cover a distance of " << n << endl;
    }
    return(0);
}
