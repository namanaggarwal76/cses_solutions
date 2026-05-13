# Stick Lengths

## Problem Link

[https://cses.fi/problemset/task/1074/](https://cses.fi/problemset/task/1074/)

## Complexity

- Time: O(n logn)
- Space: O(n)

## Approach

To minimize the summation of `|a[i]-x|` for all i, we can choose x to be the median of the array. So we sort the array, and if n is odd, then we choose x to be a[n/2], else we can choose x to be either a[n/2] or a[n/2 - 1], and we take the minimum of the two.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    if (n%2==0){
        long long res1=0;
        for (int i=0;i<n;i++){
            res1+=abs(a[i]-a[n/2]);
        }
        long long res2=0;
        for (int i=0;i<n;i++){
            res2+=abs(a[i]-a[n/2 - 1]);
        }
        cout << min(res1, res2) << endl;
    }
    else{
        long long res1=0;
        for (int i=0;i<n;i++){
            res1+=abs(a[i]-a[n/2]);
        }
        cout << res1 << endl;    
    }
}
```
