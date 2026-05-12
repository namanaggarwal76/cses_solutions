# Increaing Array

## Problem Link

[https://cses.fi/problemset/task/1094](https://cses.fi/problemset/task/1094)

## Complexity

- Time: O(n)
- Space: O(n)

## Approach

We do a greedy approach, and if a number is `<` the prev num, we increase it till its the same, so `res = res + (curr-last)`, and then update the last accordingly.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i=0;i<n;i++){
        cin >> a[i];
    }
    long long curr=a[0];
    long long res=0;
    for (long long i=1;i<n;i++){
        if (a[i]<curr) res+=curr-a[i];
        else curr=a[i];
    }
    cout << res << endl;
}
```
