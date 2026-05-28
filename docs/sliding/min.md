# Sliding Window Minimum

## Problem Link

[https://cses.fi/problemset/task/3221/](https://cses.fi/problemset/task/3221/)

## Complexity

- Time Complexity: O(n)
- Space Complexity: O(n)

## Approach

we first make the initial window of size k, and store the elements in a deque according to some rules:

1. while adding a new element, we remove all the elements from the back of the deque that are greater than or equal to the new element, then we add the new element to the back of the deque.
2. while removing an element, we keep popping till we remove all elements out of the window, and we keep the minimum element at the front of the deque, so we can easily get the minimum of the current window by looking at the front of the deque.

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
    for (int i=1;i<n;i++){
        arr[i]=(arr[i-1]*a+b)%c;
    }
    int l=0, r=0;
    deque<pair<long long, long long>> dq;
    while (r<k){
        while (!dq.empty() && dq.back().first>=arr[r]) dq.pop_back();
        dq.push_back({arr[r], r});
        r++;
    }
    long long ans=dq.front().first;
    while (r<n){
        while (!dq.empty() && dq.back().first>=arr[r]) dq.pop_back();
        dq.push_back({arr[r], r});
        while (dq.front().second<=r-k) dq.pop_front();
        ans^=dq.front().first;
        r++;
        l++;
    }
    cout << ans << endl;
}
```
