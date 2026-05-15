# Money Sums

## Problem Link

[https://cses.fi/problemset/task/1745](https://cses.fi/problemset/task/1745)

## Complexity

- Time: O(n * sum)
- Space: O(sum)

## Approach

We used the same code as [Coin Combinations II](./coin_combinations_ii.md), but in the end if number of ways `> 0` then we can make that sum, so we count the number of sums that we can make and print the values which are possible to make.

## C++ Solution

```cpp
#include <bits/stdc++.h> 
using namespace std;

const long long MOD = 1e9 + 7;

int main(){
    long long n;
    cin >> n;
    vector<long long> dp(100001, 0);
    vector<long long> coins;
    for (int i=0;i<n;i++){
        long long x;
        cin >> x;
        coins.push_back(x);
    }
    dp[0]=1;
    for (auto& val: coins){
        for (int i=100000;i>0;i--){
            if (i-val>=0) dp[i]=(dp[i]+dp[i-val])%MOD;
        }
    }
    long long res=0;
    for (int i=1;i<=100000;i++) if (dp[i]>0) res++;
    cout << res << endl;
    for (int i=1;i<=100000;i++) if (dp[i]>0) cout << i << " ";
    cout << endl;
}
```
