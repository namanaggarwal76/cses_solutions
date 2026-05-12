# Missing Number

## Problem Link

[https://cses.fi/problemset/task/1083](https://cses.fi/problemset/task/1083)

## Complexity

- Time: O(n)
- Space: O(n)

## Approach

Make a vector where `a[i]==1` if we have seen that number, else 0. So we first input all numbers, do `a[x]=1` and then loop over the vector again to find the number we have not seen yet, i.e. `a[i]==0`.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<int> a(n+1, 0);
    for (int i=0;i<n-1;i++){
        long long x;
        cin >> x;
        a[x]=1;
    }
    for (int i=1;i<=n;i++){
        if (a[i]==0){
            cout << i << endl;
            break;
        }
    }
}
```
