# Towers

## Problem Link

[https://cses.fi/problemset/task/1073/](https://cses.fi/problemset/task/1073/)

## Complexity

- Time: O(n logn)
- Space: O(n)

## Approach

we make a vector represting the current towers, and for each new element we try to put that element greedily on the best possible tower(just bigger)(therefore we use upper_bound), if there is no such tower we make a new tower with that element, and at the end the number of towers will be our answer.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> towers;
    while (n--){
        int x;
        cin >> x;
        auto it=upper_bound(towers.begin(), towers.end(), x);
        if (it==towers.end()) towers.push_back(x);
        else towers[it-towers.begin()]=x;
    }
    cout << towers.size() << endl;
}
```
