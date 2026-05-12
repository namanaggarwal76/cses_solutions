# Missing Number

## Problem Link

[https://cses.fi/problemset/task/1071](https://cses.fi/problemset/task/1071)

## Complexity

- Time: O(1) per test case
- Space: O(1)

## Approach

From observation, we figure out, diagnol value = `n^2 - (n-1)`

if `x==y`, then we have the answer.

if `x>y`, then we are going in horizontal more and then something downwards, so if x is odd, then from observation we subtract from the diagnol value, we do `diagnol value - (x-1) + (y-1)`, so we go till top, and then go y steps down, if x is even, then value from diagnol increases, so we do `diagnol value + (x-1) - (y-1)`.
  
if `x<y`, if y is even, we subtract from diagnol then add `x-1`, if y is odd then we add to diagnol and then subtract.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long x,y;
        cin >> x >> y;
        if (x==y) cout << x*x - (x-1) << endl;
        else if (x>y){
            if (x%2==0){
                cout << x*x - (x-1) + (x-1) - (y-1) << endl;
            }
            else{
                cout << x*x - (x-1) - (x-1) + (y-1) << endl;
            }
        }
        else{
            if (y%2==0){
                cout << y*y - (y-1) - (y-1) + (x-1) << endl;
            }
            else{
                cout << y*y - (y-1) + (y-1) - (x-1) << endl;
            }
        }
    }
}
```
