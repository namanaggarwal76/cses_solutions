# Maximum Subarray Sum

## Problem Link

[https://cses.fi/problemset/task/1643/](https://cses.fi/problemset/task/1643/)

## Complexity

- Time: O(n logn)
- Space: O(n)

## Approach

We use Kadane's algorithm, for each index, we check if the current_sum + a[i] is greater than a[i], if it is, then we add a[i] to current_sum, else we start a new subarray from index i, and we keep track of the maximum sum at any time.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    long long max_sum=a[0];
    long long curr_sum=a[0];
    for (int i=1;i<n;i++){
        curr_sum=max(curr_sum+a[i], a[i]);
        max_sum=max(max_sum, curr_sum);
    }
    cout << max_sum << endl;
}
```
