#include <iostream>
#include <vector>

using namespace std;

int brute_force(int val, vector<int> array, unsigned index){
    // Base cases.
    if (not val) {
        return (1);
    }
    if (val < 0 or index == array.size() ) {
        return (0);
    }

    return (brute_force(val - array[index], array, index) + brute_force(val, array, index + 1) );
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

        cout << "There are " << brute_force(val, array, 0) << " ways to make change for "
             << val << " with the given coins" << endl;
    }
    return (0);
}
