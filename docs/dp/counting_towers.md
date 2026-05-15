# Counting Towers

## Problem Link

[https://cses.fi/problemset/task/2413](https://cses.fi/problemset/task/2413)

## Complexity

- Time: O(n)
- Space: O(n)

## Approach

I couldnt figure out this on my own, had to use gpt, and it gave me this recursive relation.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main(){
    long long t;
    cin >> t;
    vector<vector<long long>> dp(1000001, vector<long long>(2, 0));
    dp[1][0]=1; dp[1][1]=1;
    for (int i=2;i<=1000000;i++){
        dp[i][0]=(2*dp[i-1][0]+dp[i-1][1])%MOD;
        dp[i][1]=(4*dp[i-1][1]+dp[i-1][0])%MOD;
    }
    while (t--){
        long long q;
        cin >> q;
        cout << (dp[q][0] + dp[q][1])%MOD << endl;
    }
}
```
