# Repetitions

## Problem Link

[https://cses.fi/problemset/task/1618](https://cses.fi/problemset/task/1618)

## Complexity

- Time: O(log n)
- Space: O(1)

## Approach

count of prime factors in factorial is given by n/p + n/(n^2) + n/(p^3) ....., so we find this for 5 and 2, and as 10 = 5 * 2, so both are required to make a 10 (trailing 0), so we take min(a,b).

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    int a=0, b=0;
    int curr=5;
    while (n/curr){
        a+=n/curr;
        curr*=5;
    }
    curr=2;
    while (n/curr){
        b+=n/curr;
        curr*=2;
    }
    cout << min(a,b) << endl;
}
```
