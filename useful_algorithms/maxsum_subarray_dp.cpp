#include <iostream>
#include <vector>

using namespace std;

int maxsum_sub_array(vector <int> arr){
    int maxsum = arr[0];
    int dp[arr.size()];
    dp[0] = arr[0];

    for(int i=1; i<arr.size(); ++i){
        //Max-sum sub array from 0 to i that includes i
        if(dp[i-1] > 0){
            dp[i] = arr[i] + dp[i-1];
        }
        else{
            dp[i] = arr[i];
        }
        maxsum = max(maxsum, dp[i]);
    }
    return maxsum;
}

int main(){
    int n, a;
    vector<int> arr;
    cout << "Size of the array?: ";
    cin >> n;
    cout << "Type the array: ";
    for(int i=0; i<n; ++i){
        cin >> a;
        arr.push_back(a); 
    }
    cout << "The maximum sum of a sub array is: " << maxsum_sub_array(arr) << endl;
    return 0;
}