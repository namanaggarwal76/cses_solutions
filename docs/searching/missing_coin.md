# Missing Coin Sum

## Problem Link

[https://cses.fi/problemset/task/2183/](https://cses.fi/problemset/task/2183/)

## Complexity

- Time: O(n logn)
- Space: O(n)

## Approach

if current coin is greater than what we have + 1, then we cant make the sum of what we have + 1, so we break, else we add the current coin to what we have, and at the end we return what we have + 1, which is the smallest sum that we cant make.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> coins(n);
    for (long long i=0;i<n;i++) cin >> coins[i];
    sort(coins.begin(), coins.end());
    long long ans=0;
    for (long long i=0;i<n;i++){
        if (coins[i]>ans+1) break;
        ans+=coins[i];
    }
    cout << ans+1 << endl;
}
```
