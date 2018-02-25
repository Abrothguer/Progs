#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int coin_table(int value, vector<int> array){
    int table[array.size() + 1][value + 1];

    for (unsigned i = 0; i <= array.size(); ++i) {
        for (int j = 0; j <= value; ++j) {
            if (not j) {
                table[i][j] = 1;
            }
            else if (not i) {
                table[i][j] = 0;
            }
            else if (array[i - 1] <= j) {
                table[i][j] = table[i - 1][j] + table[i][ j - array[i - 1] ];
            }
            else{
                table[i][j] = table[i - 1][j];
            }
        }
    }

    return (table[array.size()][value]);
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

        cout << "There are " << coin_table(val, array) << " ways to make change for "
             << val << " with the given coins" << endl;
    }
    return (0);
}
