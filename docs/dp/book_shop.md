# Book Shop

## Problem Link

[https://cses.fi/problemset/task/1158](https://cses.fi/problemset/task/1158)

## Complexity

- Time: O(n*x)
- Space: O(x)

## Approach

This is a classes knapsack problem, where `dp[i][j]` is the maximum number of pages we can get with a budget of i and using the first j books. We can optimize this to O(x) space by iterating backwards through the dp array when we are updating it, so that we don't overwrite values that we still need to use.

> There also exists variants with unlimited supply of each book, in that case we will iterate forward through the dp array instead of backwards, and variant where we can take ith book Ki times, see [cp_algo](https://cp-algorithms.com/dynamic_programming/knapsack.html#bounded-knapsack) for more details.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;
    vector<long long> price(n);
    vector<long long> pages(n);
    for (int i=0;i<n;i++) cin >> price[i];
    for (int i=0;i<n;i++) cin >> pages[i];

    // this is also a valid sol, but is a 2d dp so gives MLE (rte) in CSES

    // vector<vector<long long>> dp(x+1, vector<long long>(n, 0));
    // for (int i=1;i<=x;i++){
    //     if (i>=price[0]) dp[i][0]=pages[0];
    // }
    // for (int j=1;j<n;j++){
    //     for (int i=1;i<=x;i++){
    //         dp[i][j]=dp[i][j-1];
    //         if (i-price[j]>=0) dp[i][j]=max(dp[i-price[j]][j-1]+pages[j],dp[i][j-1]);
    //     }
    // }
    // cout << dp[x][n-1] << endl;


    vector<long long> dp(x+1, 0);
    for (int j=0;j<n;j++){
        for (int i=x;i>0;i--){
            if (i-price[j]>=0) dp[i]=max(dp[i-price[j]]+pages[j], dp[i]);
        }
    }
    cout << dp[x] << endl;
}
```
