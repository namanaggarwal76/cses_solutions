# Playlist

## Problem Link

[https://cses.fi/problemset/task/1141/](https://cses.fi/problemset/task/1141/)

## Complexity

- Time: O(n logn)
- Space: O(n)

## Approach

we keep a set to store the unique numbers in the current window, and we use two pointers to represent the current window, we move the right pointer to the right until we find a duplicate number, then we move the left pointer to the right until we remove the duplicate number from the set, and we keep track of the maximum size of the set at any time, which will be our answer.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    set<int> s;
    int l=0, r=0, max1=-1, len=-1;
    while (r<n){
        if (s.find(a[r])==s.end()){
            s.insert(a[r]);
            len=r-l+1;
            max1=max(max1, len);
            r++;
        }
        else{
            s.erase(a[l]);
            l++;
        }
    }
    cout << max1 << endl;
}
```
