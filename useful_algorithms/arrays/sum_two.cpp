#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

pair <int,int> sum_two(vector<int> arr, int target){
    pair <int,int> p;
    map <int,int> m;
    p.first = -1;
    p.second = -1;

    for(int i=0; i<arr.size(); ++i){
        if(m.find(target-arr[i]) != m.end()){
            p.first = m.find(target-arr[i])->second;
            p.second = i;
        }
        else{
            m[arr[i]] = i;
        }
    }
    return p;
}

vector< pair<int,int> > all_sum_two(vector<int> arr, int target){
    int high, low;
    sort(arr.begin(), arr.end());
    vector< pair<int,int> > ans;
    high = arr.size()-1;
    low = 0;

    while(low < high){
        if(arr[low]+arr[high] == target){
            ans.push_back(make_pair(arr[low],arr[high]));
            while(low < high and arr[low] == arr[low+1]) low++;
            while(low < high and arr[high] == arr[high-1]) high--;
            low++;
            high--;
        }
        else if(arr[low]+arr[high] < target){
            low++;
        }
        else{
            high--;
        }
    }
    return ans;
}

int main(){
    int n, a, target;
    cout << "Size of array: ";
    cin >> n;
    vector <int> arr;
    cout << "Type the array: ";
    for(int i=0; i<n; ++i){
        cin >> a;
        arr.push_back(a); 
    }
    cout << "Target: ";
    cin >> target;
    pair <int, int> st = sum_two(arr, target);
    if(st.first == -1){
        cout << "There are no pairs that add up to " << target << endl;
    }
    else{
        cout << "The pair in positon (" << st.first << "," << st.second << ") adds up to " << target << endl;  
        cout << "Printing all the pairs that match the target " << target << endl;
        vector< pair<int,int> > vec = all_sum_two(arr, target);
        for(int i=0; i<vec.size(); ++i){
            cout << vec[i].first << ", " << vec[i].second << endl; 
        }
    }

    return 0;
}