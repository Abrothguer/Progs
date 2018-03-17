#include <iostream>
#include <climits>
#include <vector>
#include <cmath>


using namespace std;

vector <int> segtree;

int get_xor(int qst, int qnd, int lpos, int rpos, int current) {
    if (lpos >= qst and rpos <= qnd) {
        return(segtree[current]);
    }
    if (lpos > qnd or rpos < qst) {
        return(0);
    }

    int mid = (rpos + lpos) / 2;
    return(get_xor(qst, qnd, lpos, mid, current * 2 + 1) ^ get_xor(qst, qnd, mid + 1, rpos, current * 2 + 2));
}

void make_segtree(int array[], int begin, int end, int current) {
    if (begin == end) {
        segtree[current] = array[begin];
        return;
    }

    int mid = (end + begin) / 2;
    make_segtree(array, begin, mid, current * 2 + 1);
    make_segtree(array, mid + 1, end, current * 2 + 2);

    segtree[current] = segtree[current * 2 + 1] ^ segtree[current * 2 + 2];
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

        cout << "The xor of range (" << a << ", " << b << ") = " << get_xor(a, b, 0, n - 1, 0) << endl;
    }
    return(0);
}
