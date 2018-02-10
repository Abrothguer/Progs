#include <bits/stdc++.h>

#define N 10000
#define M 10000
#define BIG 10101010

using namespace std;


int dp[N][M];

int brute_minimum(vector<int> coin, int val, int index){
    if(val == 0) return 0;
    if(val <  0) return BIG;
    if(index >= coin.size()) return BIG;
    
    return min(brute_minimum(coin, val-coin[index], index)+1, brute_minimum(coin, val, index+1));
}

int rec_minimum(vector<int> coin, int val, int index){
    if(val == 0) return 0;
    if(val <  0) return BIG;
    if(index >= coin.size()) return BIG;

    if(dp[val][index] != -1) return dp[val][index];

    return dp[val][index] = min(rec_minimum(coin, val-coin[index], index)+1, rec_minimum(coin, val, index+1));
}

int minimum_change(int coin[], int val, int siz){
    int memo[val+1];
    memo[0] = 0;
    for(int i=1; i<=val; ++i){
        memo[i] = BIG;
    }

    for(int i=1; i<=val; ++i){
        for(int j=0; j<siz; ++j){
            if(coin[j] <= i){
                if(memo[i-coin[j]] != BIG and memo[i-coin[j]]+1 < memo[i]){
                    memo[i] = memo[i-coin[j]]+1;
                }   
            }
        }
    }
    return memo[val];
}
