# Distinct Numbers

## Problem Link

[https://cses.fi/problemset/task/1621/](https://cses.fi/problemset/task/1621/)

## Complexity

- Time: O(n logn) (logn due to set)
- Space: O(n)

## Approach

We put all elements in an `unordered_set`, and finally return its size, idk why normal set was giving tle on large n values (maybe due to colliding hashes).

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    set<long long> s;
    for (int i=0;i<n;i++){
        long long x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
}
```
