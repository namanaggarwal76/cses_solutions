# Two Knights

## Problem Link

[https://cses.fi/problemset/task/1072](https://cses.fi/problemset/task/1072)

## Approach

My approach is kinda brute force, calucalting for all possible types of squares in a board of size k*k, where k>=4, and then adding all of them up and dividing by 2 (because double counting), I later found out there is better approach to do so which is total squares in attacking squares,

```bash
(n^2(n^2-1))/2 - 4(n-1)(n-2)
```

## Complexity

- Time: O(k)
- Space: O(1)

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long k;
    cin >> k;
    if (k>=1) cout << 0 << endl;
    if (k>=2) cout << 6 << endl;
    if (k>=3) cout << 28 << endl;
    for (long long i=4;i<=k;i++){
        cout << ((i-4)*(i-4)*(i*i - 9) + 4*(i*i - 3) + 8*(i*i - 4) + (i*i - 5)*(i-4)*4 + 4*(i*i-5) + (i*i - 7)*(i-4)*4)/2 << endl;
    }
}
```
