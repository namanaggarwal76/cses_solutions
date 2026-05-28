# Collecting Numbers II

## Problem Link

[https://cses.fi/problemset/task/2217/](https://cses.fi/problemset/task/2217/)

## Complexity

- Time: O(n+m)
- Space: O(n)

## Approach

we store the position of each number, and if any bigger num has a position less then smaller num, then we need to make a new round to collect the bigger num, so we count how many times this happens for the initial number number, then as we know that we are checking i and i+1 from left to right, so if we swap 2 numbers max 4 pairs would be affected, so we check those pairs before and after the swap, to see if there is any diff in the contribution of those pairs to the answer, and we update the answer according to that, we use a set because if the values are say k and k+1, then if we directly use all 4 pairs, then there will be double counting of the pair k and k+1, so we use a set to make sure that we only count it once.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pos(n+1);
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) pos[a[i]]=i;
    int res=0;
    for (int i=1;i<n;i++){
        if (pos[i+1]<pos[i]) res++;
    }
    cout << res+1 << endl;
}
```
