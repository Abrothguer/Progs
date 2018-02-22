#include <iostream>

using namespace std;

int lcs(string a, string b) {
    int lcsmax[a.size() + 1][b.size() + 1];

    for (unsigned i = 0; i <= a.size(); ++i) {
        for (unsigned j = 0; j <= b.size(); ++j) {
            if (not i or not j) {
                lcsmax[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1]) {
                lcsmax[i][j] = lcsmax[i - 1][j - 1] + 1;
            }
            else{
                lcsmax[i][j] = max(lcsmax[i - 1][j], lcsmax[i][j - 1]);
            }
        }
    }

    return(lcsmax[a.size()][b.size()]);
}

string lcs_string(string a, string b) {
    int lcsmax[a.size() + 1][b.size() + 1];

    for (unsigned i = 0; i <= a.size(); ++i) {
        for (unsigned j = 0; j <= b.size(); ++j) {
            if (not i or not j) {
                lcsmax[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1]) {
                lcsmax[i][j] = lcsmax[i - 1][j - 1] + 1;
            }
            else{
                lcsmax[i][j] = max(lcsmax[i - 1][j], lcsmax[i][j - 1]);
            }
        }
    }
    int    c = lcsmax[a.size()][b.size()];
    string ans(lcsmax[a.size()][b.size()], ' ');

    for (int i = a.size(); i > 0; ) {
        for (int j = b.size(); j > 0 and i > 0; ) {
            if (lcsmax[i][j] != max(lcsmax[i][j - 1], lcsmax[i - 1][j])) {
                ans[c] = a[i - 1];
                i--;
                j--;
                c--;
            }
            else if (lcsmax[i][j - 1] == lcsmax[i][j]) {
                j--;
            }
            else if (lcsmax[i - 1][j] == lcsmax[i][j]) {
                i--;
            }
        }
    }
    return(ans);
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

        cout << "The length of the Longest Commom Subsequence is: " << lcs(a, b) << endl;
    }
    return(0);
}
