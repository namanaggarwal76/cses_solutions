# Coin Piles

## Problem Link

[https://cses.fi/problemset/task/1754](https://cses.fi/problemset/task/1754)

## Approach

Let m be number of step 1, and n be number of step 2.

```bash
a - 2m - n = 0
b - m - 2n = 0
```

so

```bash
a = 2m + n
b = m + 2n
a - 2b = -3n
b - 2a = -3m
```

so `a-2b` and `b-2a` both should be divisible by -3 to get a non negative integer.

## Complexity

- Time: O(1) per test case
- Space: O(1)

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long a,b;
        cin >> a >> b;
        if ((a-2*b)%3 == 0 and a-2*b <= 0 and (b-2*a)%3 == 0 and b-2*a <= 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
```
