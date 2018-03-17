#include <iostream>
#include <vector>

using namespace std;

int coin_table(int value, vector<int> array){
    int table[value + 1];

    table[0] = 1;
    for (int i = 1; i <= value; ++i) {
        table[i] = 0;
    }

    for (unsigned i = 0; i < array.size(); ++i) {
        for (int j = array[i]; j <= value; ++j) {
            table[j] += table[j - array[i]];
        }
    }

    return (table[value]);
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
