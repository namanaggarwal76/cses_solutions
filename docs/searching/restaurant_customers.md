# Restaurant Customers

## Problem Link

[https://cses.fi/problemset/task/1619/](https://cses.fi/problemset/task/1619/)

## Complexity

- Time: O(n logn)
- Space: O(n)

## Approach

We store the arrival and leaving times in a vector of pairs, where the first value is the time and the second value is 1 for arrival and -1 for leaving, then we sort the vector, and loop over it, if we see an arrival we do count++, else count--, and we keep track of the maximum count at any time.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    vector<pair<long long, long long>> arr;
    for (int i=0;i<n;i++){
        long long a,b;
        cin >> a >> b;
        arr.push_back({a, 1});
        arr.push_back({b, -1});
    }
    sort(arr.begin(), arr.end());
    int count=0;
    int max1=0;
    for (int i=0;i<2*n;i++){
        count+=arr[i].second;
        max1=max(max1, count);
    }
    cout << max1 << endl;
}
```
