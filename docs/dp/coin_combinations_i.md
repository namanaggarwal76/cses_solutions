# Coin Combinations I

## Problem Link

[https://cses.fi/problemset/task/1635](https://cses.fi/problemset/task/1635)

## Complexity

- Time: O(n*c)
- Space: O(c+n)

## Approach

Similar to the last question, but this time we store the num of ways to make a sum instead of the minimum num, so the transition changes from min(dp[i], dp[i-val]+1) to dp[i]+dp[i-val].

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
        dp[x]=1;
    }
    for (int i=0;i<=1000000;i++){
        for (auto& val: coins){
            if (i-val>=0) dp[i]=(dp[i]+dp[i-val])%MOD;
        }
    }
    cout << dp[target] << endl;
}
```
