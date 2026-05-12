# Permutations

## Problem Link

[https://cses.fi/problemset/task/1070](https://cses.fi/problemset/task/1070)

## Complexity

- Time: O(n)
- Space: O(1)

## Approach

All odd numbers have difference >1, and all even have difference >1, so if we put all odd first, then all even it shouldn't be a problem.

if n is odd, then the perm becomes:
    ```1 3 5 7 ... n 2 4 6 8 10 ... n-1```

if n is even:
    ```1 3 5 7 .... n-1 2 4 6 8 ... n```

Then we see the edge cases, so ```n==2``` and ```n==3``` wont work, because no permutation exist, and for ```n==4``` this method wont work, so find one permutation manually, and for ```n==1``` it is just one element so print it direclty.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    if (n==1) cout << "1" << endl;
    else if (n==2 || n==3) cout << "NO SOLUTION" << endl;
    else if (n==4) cout << "3 1 4 2" << endl;
    else{
        for (int i=1;i<=n;i+=2) cout << i << " ";
        for (int i=2;i<=n;i+=2) cout << i << " ";
        cout << endl;
    }
}
```
