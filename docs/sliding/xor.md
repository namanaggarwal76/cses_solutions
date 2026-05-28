# Sliding Window Minimum

## Problem Link

[https://cses.fi/problemset/task/3426/](https://cses.fi/problemset/task/3426/)

## Complexity

- Time Complexity: O(n)
- Space Complexity: O(n)

## Approach

we first make the initial window of size k and calculate the xor of it, then we keep adding the next element and removing the first element of the previous window from the xor, and keep xoring the new window's xor to the result.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    long long x,a,b,c;
    cin >> x >> a >> b >> c;
    vector<long long> arr(n);
    arr[0]=x;
    for (long long i=1;i<n;i++){
        arr[i]=(arr[i-1]*a+b)%c;
    }
    long long l=0, r=0;
    long long ans=0;
    long long res=0;
    while (r<k){
        ans^=arr[r];
        r++;
    }
    res^=ans;
    long long left=arr[0];
    while (r<n){
        ans^=arr[r];
        r++;
        ans^=left;
        l++;
        left=arr[l];
        res^=ans;
    }
    cout << res << endl;
}
```
