#include <iostream>
#include <vector>

using namespace std;

int knapsack_bf(vector <pair <int, int> > items, int weight, unsigned index) {
    if (index >= items.size() or weight < 0) {
        return(0);
    }
    // DONT TAKE OR TAKE!
    if (weight < items[index].first) {
        return(knapsack_bf(items, weight, index + 1));
    }
    return(max(knapsack_bf(items, weight, index + 1),
               items[index].second + knapsack_bf(items, weight - items[index].first, index + 1)));
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
             << knapsack_bf(items, w, 0) << endl;
    }
    return(0);
}
