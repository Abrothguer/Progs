#include <iostream>

using namespace std;

int edit_string_bf(string a, string b, int n, int m) {
    // Bottom of string a, m additions necessary.
    if (not n) {
        return(m);
    }

    // Bottom of string b, n additions required.
    if (not m) {
        return(n);
    }

    // Both end letters are the same - no change required.
    if (a[n - 1] == b[m - 1]) {
        return(edit_string_bf(a, b, n - 1, m - 1));
    }

    int add, rem, rep;

    // Adds a letter to the first string -> size of second string decreases.
    add = edit_string_bf(a, b, n, m - 1);

    // Removes a letter of the first string -> size of first string decreases.
    rem = edit_string_bf(a, b, n - 1, m);

    // Replaces a letter of the first string -> both sizes decrease.
    rep = edit_string_bf(a, b, n - 1, m - 1);

    // Return the modification of the current letter plus the minimum modification
    // required to change the rest of the string.
    return(1 + min(add, min(rem, rep)));
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

        cout << edit_string_bf(a, b, a.size(), b.size()) << " changes are necessary to make "
             << a << " = " << b << endl;
    }

    return(0);
}
