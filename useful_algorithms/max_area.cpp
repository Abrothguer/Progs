#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int max_area(vector<int> arr){
    int area, left, right, calc;
    
    area = -1;
    left = 0;
    right = arr.size()-1;

    while(left != right){
        calc = min(arr[left], arr[right])*(right-left);
        area = max(calc,area);
        if(arr[right] < arr[left]) --right;
        else ++left;
    }

    return area;
}

int main(){
    int n, a;
    vector<int> arr;

    cout << "How many columns?: ";
    cin >> n;
    cout << "Type the values of the columns: ";
    for(int i=0; i<n; ++i){
        cin >> a;
        arr.push_back(a);
    }

    cout << "The maximum area is: " << max_area(arr) << endl;
    return 0;
}