# Weird Algorithm

## Problem Link

[https://cses.fi/problemset/task/1068](https://cses.fi/problemset/task/1068)

## Complexity

- Time: O(number of steps) # no proven formula yet
- Space: O(1)

## Approach

We Loop till n!=1, and if n is odd, then ```n' = 3*n + 1```, else ```n' = n/2```.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    while (n!=1){
        cout << n << " ";
        if (n%2) n=n*3+1;
        else n=n/2;
    }
    cout << n << endl;
}
```
