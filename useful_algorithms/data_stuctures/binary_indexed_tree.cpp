#include <iostream>

using namespace std;

void update(int bitree[], int size, int index, int value){
    for (index = index + 1; index <= size; index += index & (-index) ) {
        bitree[index] += value;
    }
}

void make_bit(int array[], int size, int bitree[]){
    for (int i = 0; i <= size; ++i) {
        bitree[i] = 0;
    }
    for (int i = 0; i < size; ++i) {
        update(bitree, size, i, array[i]);
    }
}

int get_sum(int bitree[], int index){
    int ac = 0;
    for (index = index + 1; index > 0; index -= index & (-index) ) {
        ac += bitree[index];
    }
    return (ac);
}

int main(){
    int n, a, b;
    cout << "Type the nro of elements: ";
    cin >> n;
    if (n <= 0) {
        return (0);
    }

    int array[n];
    int bitree[n + 1];

    cout << "Type the elements: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    make_bit(array, n, bitree);



    while (true) {
        cout << "Type the range (a,b): ";
        cin >> a >> b;

        if (b < a or b >= n or a < 0) {
            break;
        }

        cout << "The sum of range (" << a << ", " << b << ") = " << get_sum(bitree, b) - get_sum(bitree, a - 1) << endl;
    }
    return (0);
}
