# Sum of Two Values

## Problem Link

[https://cses.fi/problemset/task/1640/](https://cses.fi/problemset/task/1640/)

## Complexity

- Time: O(n logn)
- Space: O(n)

## Approach

We first sort, and then use the 2 pointer approach (2 sum), to find the required pair.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;
    vector<pair<long long,int>> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(), a.end());
    int l=0,r=n-1;
    while (l < r){
        long long sum=a[l].first+a[r].first;
        if (sum == x){
            cout << a[l].second << " " << a[r].second << endl;
            return 0;
        }
        if (sum < x) l++;
        else r--;
    }
    cout << "IMPOSSIBLE" << endl;
}
```
