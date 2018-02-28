#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <int> segtree;

int make_segtree(int array[], int begin, int end, int cur) {
    if (begin == end) {
        segtree[cur] = array[begin];
        return(segtree[cur]);
    }

    int left, right, mid;

    mid   = (end + begin) / 2;
    left  = make_segtree(array, begin, mid, cur * 2 + 1);
    right = make_segtree(array, mid + 1, end, cur * 2 + 2);

    segtree[cur] = left + right;
    return(segtree[cur]);
}

int get_range_sum(int qst, int qnd, int lpos, int rpos, int cur) {
    if (lpos >= qst and rpos <= qnd) {
        return(segtree[cur]);
    }
    if (rpos <qst or lpos> qnd) {
        return(0);
    }

    int mid = (rpos + lpos) / 2;

    return(get_range_sum(qst, qnd, lpos, mid, cur * 2 + 1) +
           get_range_sum(qst, qnd, mid + 1, rpos, cur * 2 + 2));
}

int main() {
    int n, a, b;

    cout << "Type the nro of elements: ";
    cin >> n;
    if (n <= 0) {
        return(0);
    }

    segtree = vector <int> (pow(2, ceil(log2(n)) + 1), 0);

    cout << "Type the value of the elements: " << endl;
    int array[n];
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

        cout << "The sum of range (" << a << ", " << b << ") = " << get_range_sum(a, b, 0, n - 1, 0) << endl;
    }
    return(0);
}
