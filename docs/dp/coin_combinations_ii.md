# Coin Combinations II

## Problem Link

[https://cses.fi/problemset/task/1636](https://cses.fi/problemset/task/1636)

## Complexity

- Time: O(n*c)
- Space: O(n+c)

## Approach

so this is similar to last 2 questions, but in this we want combinations, so we just flip the loops in the dp transition, and base case changes to dp[0]=1, and we don't set dp[val]=1 for the coins, because we can use the same coin multiple times, so we will get that in the transition itself.

## C++ Solution

```cpp
#include <bits/stdc++.h> 
using namespace std;

const long long MOD = 1e9 + 7;

int main(){
    long long n,target;
    cin >> n >> target;
    vector<long long> dp(1000001, 0);
    vector<long long> coins;
    for (int i=0;i<n;i++){
        long long x;
        cin >> x;
        coins.push_back(x);
    }
    dp[0]=1;
    for (auto& val: coins){
        for (int i=0;i<=1000000;i++){
            if (i-val>=0) dp[i]=(dp[i]+dp[i-val])%MOD;
        }
    }
    cout << dp[target] << endl;
}
```
