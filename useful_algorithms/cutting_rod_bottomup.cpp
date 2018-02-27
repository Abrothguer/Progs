#include <iostream>

using namespace std;

int cut_rod(int l, int array[]) {
    int table[l + 1][l + 1];

    for (int i = 0; i <= l; ++i) {
        for (int j = 0; j <= l; ++j) {
            if (not i or not j) {
                table[i][j] = 0;
            }
            else{
                if (i <= j) {
                    table[i][j] = max(table[i - 1][j], array[i - 1] + table[i][j - i]);
                }
                else{
                    table[i][j] = table[i - 1][j];
                }
            }
        }
    }

    return(table[l][l]);
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

        cout << "The maximum value that can be achieved is " << cut_rod(l, array) << endl;
    }
    return(0);
}
