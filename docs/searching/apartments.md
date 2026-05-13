# Distinct Numbers

## Problem Link

[https://cses.fi/problemset/task/1084/](https://cses.fi/problemset/task/1084/)

## Complexity

- Time: O(n logn)
- Space: O(n)

## Approach

We store the preferred ranges ({x-k, x+k}), sort by the first value, and sort the apartments in ascending as well, then for each preference we find if there is an apartment, if yes then count++, and we move to the next preference and the next apartment, else we just move to the next preference.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    vector<pair<long long,long long>> a;
    vector<long long> b;
    cin >> n >> m >> k;
    for (int i=0;i<n;i++){
        long long x;
        cin >> x;
        a.push_back({x-k, x+k});
    }
    for (int i=0;i<m;i++){
        long long x;
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    int idx=0;
    for (int i=0;i<n;i++){
        while (idx<m && b[idx]<a[i].first) idx++;
        if (idx<m && b[idx]<=a[i].second){
            ans++;
            idx++;
        }
    }
    cout << ans << endl;
}
```
