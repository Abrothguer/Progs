#include <bits/stdc++.h>

#define N 10000
#define M 10000

using namespace std;

int dp[N][M];

int brute_coin(vector<int> coin, int val, int index){
    if(val == 0) return 1;
    if(val <  0) return 0;

    if(index == coin.size()) return 0;

    return brute_coin(coin, val-coin[index], index) + brute_coin(coin, val, index+1);
}

int rec_coin_change(vector<int> coin, int val, int index){
    if(val == 0) return 1;
    if(val <  0) return 0;

    if(index == coin.size()) return 0;

    if(dp[val][index] != -1) return dp[val][index];

    return dp[val][index] = rec_coin_change(coin, val-coin[index], index) + rec_coin_change(coin, val, index+1);
}

int coin_change(vector<int> coin, int val){
    int memo[val+1][coin.size()];
    for(int i=0; i<coin.size(); ++i){
        memo[0][i] = 1;
    }
    int g, ng;
    for(int i=1; i<val+1; ++i){
        for(int j=0; j<coin.size(); ++j){
            g = (i-coin[j] >= 0) ? memo[i-coin[j]][j] : 0;
            ng = (j >= 1) ? memo[i][j-1] : 0;
            memo[i][j] = g + ng; 
        }
    }
    return memo[val][coin.size()-1];
}
