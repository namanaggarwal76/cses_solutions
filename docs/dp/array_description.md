# Array Description

## Problem Link

[https://cses.fi/problemset/task/1746](https://cses.fi/problemset/task/1746)

## Complexity

- Time: O(n*m)
- Space: O(n*m)

## Approach

Similar to KnapSack, we can use a 2D DP array where `dp[i][j]` represents the number of ways to fill the first `i` elements of the array such that the `i`-th element is `j`. We can transition from `dp[i-1][j-1]`, `dp[i-1][j]`, and `dp[i-1][j+1]` to `dp[i][j]` if the current element is either 0 (which means it can take any value) or equal to `j`.

This can also be compressed into a 1D DP, because `dp[i][j]` only depends on `dp[i-1][j-1]`, `dp[i-1][j]`, and `dp[i-1][j+1]`.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main(){
    long long n,m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    vector<vector<long long>> dp(n, vector<long long>(m+1, 0));
    if (a[0]==0){
        for (int x=1;x<=m;x++) {
            dp[0][x]=1;
        }
    }
    else dp[0][a[0]] = 1;
    for (int i=1;i<n;i++){
        for (int j=1;j<=m;j++){
            if (a[i]!=0 && j!=a[i]) continue;
            if (i-1>=0 && j-1>=0) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%MOD;
            if (i-1>=0) dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            if (i-1>=0 && j+1<=m) dp[i][j]=(dp[i][j]+dp[i-1][j+1])%MOD;
        }
    }
    long long sum1=0;
    for (int i=1;i<=m;i++) sum1=(sum1+dp[n-1][i])%MOD;
    cout << sum1 << endl;
}
```
