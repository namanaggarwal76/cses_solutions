# Minimizing Coins

## Problem Link

[https://cses.fi/problemset/task/1634](https://cses.fi/problemset/task/1634)

## Complexity

- Time Complexity: O(n*c)
- Space Complexity: O(n+c)

## Approach

for any value, we can use the given coins only, and the dp stored the num of coins required to reach that, so initially we set all the dp to +inf, and for given coins we set dp[coin]=1 (directly 1 coin), then we loop from i=0 to last, and check wheather any value i-coin can be formed, if yes, we take the minimum of all dp[i-coins]+1, (+1 because we need to add the current coin), and at the end we check if dp[target] is still +inf, if yes, then we can't form the target, else we print the dp[target] which is the minimum number of coins required to form the target.

## C++ Solution

```cpp
#include <bits/stdc++.h> 
using namespace std;

int main(){
    long long n,target;
    cin >> n >> target;
    vector<long long> dp(1000001, LLONG_MAX);
    vector<long long> coins;
    for (int i=0;i<n;i++){
        long long x;
        cin >> x;
        coins.push_back(x);
        dp[x]=1;
    }
    for (int i=0;i<=1000000;i++){
        for (auto& val: coins){
            if (i-val>=0 && dp[i-val]!=LLONG_MAX) dp[i]=min(dp[i], dp[i-val]+1);
        }
    }
    if (dp[target]==LLONG_MAX) cout << -1 << endl;
    else cout << dp[target] << endl;
}
```
