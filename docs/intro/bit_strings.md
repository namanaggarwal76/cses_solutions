# Increaing Array

## Problem Link

[https://cses.fi/problemset/task/1617](https://cses.fi/problemset/task/1617)

## Complexity

- Time: O(log n)
- Space: O(1)

## Approach

We do binary exponentiation, to find the number of strings i.e. (2^n)

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    const long long MOD = 1e9 + 7;
    long long n;
    cin >> n;
    long long res=1;
    long long a=2;
    while (n>0){
        if (n&1){
            res=(res*a)%MOD;
        }
        a=(a*a)%MOD;
        n=n>>1;
    }
    cout << res << endl;
}
```
