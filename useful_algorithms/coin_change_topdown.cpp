#include <iostream>
#include <vector>

using namespace std;

int memo[30][500];

int coin_memo(int value, vector<int> array, unsigned index){
    if (not value) {
        return (1);
    }
    if (value < 0 or index == array.size() ) {
        return (0);
    }
    if (memo[index][value] != -1) {
        return (memo[index][value]);
    }

    return (memo[index][value] = coin_memo(value - array[index], array, index)
                                 + coin_memo(value, array, index + 1) );
}

int main(){
    int a, c, val;
    while (true) {
        cout << "Type the value: ";
        cin >> val;
        if (val <= 0) {
            break;
        }

        cout << "How many coins: ";
        cin >> c;
        if (c <= 0) {
            break;
        }

        vector <int> array;
        cout << "Type the coin values: " << endl;
        for (int i = 0; i < c; ++i) {
            cin >> a;
            array.push_back(a);
        }

        for (int i = 0; i <= c; ++i) {
            for (int j = 0; j <= val; ++j) {
                memo[i][j] = -1;
            }
        }

        cout << "There are " << coin_memo(val, array, 0) << " ways to make change for "
             << val << " with the given coins" << endl;
    }
    return (0);
}
