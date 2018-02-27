#include <iostream>
#include <climits>

using namespace std;

int cut_rod_bf(int l, int array[]) {
    int temp, best = INT_MIN;

    if (not l) {
        return(0);
    }

    for (int i = 0; i < l; ++i) {
        temp = cut_rod_bf(l - i - 1, array);
        if (temp == INT_MIN) {
            continue;
        }
        best = max(best, array[i] + cut_rod_bf(l - i - 1, array));
    }

    return(best);
}

int main() {
    int l;

    while (true) {
        cout << "Type the length: ";
        cin >> l;
        if (l <= 0) {
            break;
        }

        cout << "Type the values: " << endl;
        int array[l];
        for (int i = 0; i < l; ++i) {
            cin >> array[i];
        }

        cout << "The maximum value that can be achieved is " << cut_rod_bf(l, array) << endl;
    }
    return(0);
}
