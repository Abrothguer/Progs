#include <iostream>

#define MAX    50

using namespace std;

int memo[MAX][MAX];

int edit_string_memo(string a, string b, int n, int m) {
    if (memo[n][m] != -1) {
        return(memo[n][m]);
    }

    if (a[n - 1] == b[m - 1]) {
        return(memo[n][m] = edit_string_memo(a, b, n - 1, m - 1));
    }

    int add, rem, rep;

    add = edit_string_memo(a, b, n, m - 1);
    rem = edit_string_memo(a, b, n - 1, m);
    rep = edit_string_memo(a, b, n - 1, m - 1);

    return(memo[n][m] = 1 + min(add, min(rem, rep)));
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

        for (unsigned i = 0; i <= a.size(); ++i) {
            for (unsigned j = 0; j <= b.size(); ++j) {
                memo[i][j] = not i ? j : not j ? i : -1;
            }
        }

        cout << edit_string_memo(a, b, a.size(), b.size()) << " changes are necessary to make "
             << a << " = " << b << endl;
    }

    return(0);
}
