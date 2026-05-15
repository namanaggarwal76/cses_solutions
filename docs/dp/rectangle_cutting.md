# Rectangle Cutting

## Problem Link

[https://cses.fi/problemset/task/1744](https://cses.fi/problemset/task/1744)

## Complexity

- Time: O(n*m)
- Space: O(n*m)

## Approach

We write a dp solution with `dp[i][j]` being the minimum number of cuts needed to cut a rectangle of size i*j into squares, we can cut it into two rectangles of size k*j and (i-k)*j for all k from 1 to i-1, or we can cut it into two rectangles of size i*k and i*(j-k) for all k from 1 to j-1, and we take the minimum of all these cuts plus one (for the cut we just made), and if i==j then `dp[i][j]=0` since it's already a square.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;
    cin >> n >> m;
    vector<vector<long long>> dp(n+1, vector<long long>(m+1, LLONG_MAX));
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            if (i==j) dp[i][j]=0;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (i==j) continue;
            for (int k=1;k<i;k++){
                dp[i][j]=min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            }
            for (int k=1;k<j;k++){
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
            }
        }
    }
    cout << dp[n][m] << endl;
}
```
