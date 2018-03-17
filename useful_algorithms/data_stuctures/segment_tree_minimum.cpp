#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

vector <int> segtree;

void make_segtree(int array[], int start, int end, int current) {
    if (start == end) {
        segtree[current] = array[start];
        return;
    }

    int mid = (end + start) / 2;

    make_segtree(array, start, mid, current * 2 + 1);
    make_segtree(array, mid + 1, end, current * 2 + 2);

    segtree[current] = min(segtree[current * 2 + 1], segtree[current * 2 + 2]);
}

int get_min(int qst, int qnd, int lpos, int rpos, int current) {
    if (lpos >= qst and rpos <= qnd) {
        return(segtree[current]);
    }
    if (lpos > qnd or rpos < qst) {
        return(INT_MAX);
    }

    int mid = (lpos + rpos) / 2;

    return(min(get_min(qst, qnd, lpos, mid, current * 2 + 1),
               get_min(qst, qnd, mid + 1, rpos, current * 2 + 2)));
}

int main() {
    int n, a, b;

    cout << "Type the number of elements: ";
    cin >> n;
    if (n <= 0) {
        return(0);
    }

    segtree = vector <int> (pow(2, ceil(log2(n)) + 1), INT_MAX);
    int array[n];

    cout << "Type the elements: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    make_segtree(array, 0, n - 1, 0);
    while (true) {
        cout << "Type the range (a,b): ";
        cin >> a >> b;

        if (b < a or b >= n or a < 0) {
            break;
        }

        cout << "The minimum element on range (" << a << ", " << b << ") = " << get_min(a, b, 0, n - 1, 0) << endl;
    }
    return(0);
}
