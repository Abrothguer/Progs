#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector <pair <int, int> > items, int weight, int n) {
    int table[n + 1][weight + 1];

    for (int i = 0; i <= n; ++i) {
        table[i][0] = 0;
    }
    for (int i = 0; i <= weight; ++i) {
        table[0][i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= weight; ++j) {
            if (items[i - 1].first > j) {
                table[i][j] = table[i - 1][j];
            }
            else{
                table[i][j] = max(table[i - 1][j], items[i - 1].second + table[i - 1][j - items[i - 1].first]);
            }
        }
    }
    return(table[n][weight]);
}

int main() {
    int w, n, a, b;

    while (true) {
        cout << "What is the maximum weight your backpack can carry? ";
        cin >> w;
        if (w <= 0) {
            break;
        }

        cout << "How many items do you have available? ";
        cin >> n;
        if (n <= 0) {
            break;
        }

        cout << "Type the weight and the value of each item: " << endl;
        // 1st - Weight, 2nd - Value.
        vector <pair <int, int> > items;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            items.push_back(make_pair(a, b));
        }

        cout << "The maximum value you can carry on your backpack is "
             << knapsack(items, w, n) << endl;
    }
    return(0);
}
