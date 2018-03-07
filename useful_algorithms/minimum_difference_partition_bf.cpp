#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int part_difference_bf(vector <int> array, int sum1, int sum2, unsigned index) {
    if (index == array.size()) {
        return(abs(sum1 - sum2));
    }

    return(min(part_difference_bf(array, sum1 + array[index], sum2 - array[index], index + 1),
               part_difference_bf(array, sum1, sum2, index + 1)));
}

int main() {
    int n, sum2, sum1, a;

    while (true) {
        cout << "How many elements: ";
        cin >> n;
        if (n <= 0) {
            break;
        }

        vector <int> array;
        sum1 = sum2 = 0;

        cout << "Type the elements: " << endl;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            array.push_back(a);
            sum2 += a;
        }

        cout << "The minimum difference is : " << part_difference_bf(array, sum1, sum2, 0) << endl;
    }
    return(0);
}
