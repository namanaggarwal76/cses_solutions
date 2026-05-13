# Ferris Wheel

## Problem Link

[https://cses.fi/problemset/task/1090/](https://cses.fi/problemset/task/1090/)

## Complexity

- Time: O(n logn)
- Space: O(n)

## Approach

We use a 2-pointer approach, we sort the weights in ascending order, and we have two pointers, one at the start and one at the end, if the sum of the weights at these pointers is less than or equal to x, then we can put them together in a gondola, so we move both pointers, else we can only put the heavier one in a gondola, so we move the right pointer. We keep doing this till the pointers meet.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    int l=0;
    int r=n-1;
    int res=0;
    while (l<r){
        if (a[l]+a[r]>x){
            res++;
            r--;
        }
        else{
            res++;
            r--;
            l++;
        }
    }
    if (l==r) res++;
    cout << res << endl;
}
```
