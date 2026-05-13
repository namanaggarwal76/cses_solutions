# Tower of Hanoi

## Problem Link

[https://cses.fi/problemset/task/2165](https://cses.fi/problemset/task/2165)

## Complexity

- Time: O(2^n)
- Space: O(1)

## Approach

To move a tower of size n from 1 to 3, first we move the tower of n-1 from 1 to 2, then move the last block from 1 to 3, and then the n-1 tower from 2 to 3. We use this same idea in recursion.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

void func(int n, int curr, int final, int help){
    if (n==0) return;
    func(n-1, curr, help, final);
    cout << curr << " "  << final << endl;
    func(n-1, help, final, curr);
}

int main(){
    int n;
    cin >> n;
    cout << (1LL << n) - 1 << endl;
    func(n, 1, 3, 2);
}
```
