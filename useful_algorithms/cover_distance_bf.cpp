#include <iostream>

using namespace std;

int cover_distance(int n) {
    if (not n) {
        return(1);
    }

    int count = 0;

    for (int i = 1; i <= n; ++i) {
        count += cover_distance(n - i);
    }
    return(count);
}

int main() {
    int n;

    while (true) {
        cout << "Type the distance: ";
        cin >> n;
        if (n < 0) {
            break;
        }

        cout << "There are " << cover_distance(n) << " to cover a distance of " << n << endl;
    }
    return(0);
}
