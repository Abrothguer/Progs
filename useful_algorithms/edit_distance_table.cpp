#include <iostream>

using namespace std;


int edit_string_table(string a, string b, int n, int m) {
    int table[n + 1][m + 1];

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (not i) {
                table[i][j] = j;
            }
            else if (not j) {
                table[i][j] = i;
            }
            else if (a[i - 1] == b[j - 1]) {
                table[i][j] = table[i - 1][j - 1];
            }
            else{
                table[i][j] = 1 + min(table[i - 1][j - 1], min(table[i - 1][j], table[i][j - 1]));
            }
        }
    }

    return(table[n][m]);
}

int main() {
    string a, b;

    while (true) {
        cout << "Type the first string: ";
        if (not (cin >> a)) {
            break;
        }

        cout << "Type the second string: ";
        if (not (cin >> b)) {
            break;
        }

        cout << edit_string_table(a, b, a.size(), b.size()) << " changes are necessary to make "
             << a << " = " << b << endl;
    }

    return(0);
}
