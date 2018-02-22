#include <iostream>

using namespace std;

int lrs(string a) {
    int table[a.size() + 1][a.size() + 1];

    for (unsigned i = 0; i <= a.size(); ++i) {
        for (unsigned j = 0; j <= a.size(); ++j) {
            if (not i or not j) {
                table[i][j] = 0;
            }
            else if (a[i - 1] == a[j - 1] and i != j) {
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            else{
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }
    return(table[a.size()][a.size()]);
}

string lrs_string(string a) {
    int table[a.size() + 1][a.size() + 1];

    for (unsigned i = 0; i <= a.size(); ++i) {
        for (unsigned j = 0; j <= a.size(); ++j) {
            if (not i or not j) {
                table[i][j] = 0;
            }
            else if (a[i - 1] == a[j - 1] and i != j) {
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            else{
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }

    int    c = table[a.size()][a.size()] - 1;
    string ans(table[a.size()][a.size()], ' ');

    for (int i = a.size(); i > 0; ) {
        for (int j = a.size(); j > 0 and i > 0; ) {
            if (table[i][j] > max(table[i - 1][j], table[i][j - 1])) {
                ans[c] = a[i - 1];
                --i;
                --j;
                --c;
            }
            else if (table[i][j] == table[i - 1][j]) {
                --i;
            }
            else if (table[i][j] == table[i][j - 1]) {
                --j;
            }
        }
    }

    return(ans);
}

int main() {
    string a;

    while (true) {
        cout << "Type your string: ";
        if (not (cin >> a)) {
            break;
        }

        cout << "The Logest Repeating Subsequence is: " << lrs_string(a) << endl;
    }
}
