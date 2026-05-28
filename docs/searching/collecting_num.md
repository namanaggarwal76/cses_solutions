# Collecting Numbers

## Problem Link

[https://cses.fi/problemset/task/2216/](https://cses.fi/problemset/task/2216/)

## Complexity

- Time: O(n)
- Space: O(n)

## Approach

we store the position of each number, and if any bigger num has a position less then smaller num, then we need to make a new round to collect the bigger num, so we count how many times this happens, and add 1 to it for the first round.

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
