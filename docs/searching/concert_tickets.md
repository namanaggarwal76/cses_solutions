# Concert Tickets

## Problem Link

[https://cses.fi/problemset/task/1091/](https://cses.fi/problemset/task/1091/)

## Complexity

- Time: O(n logn)
- Space: O(n)

## Approach

We store the ticket prices in a multiset, and for each customer we find the upper bound of their price, if it is the begining of the set, then there is no ticket for them, else we move one step back and give them that ticket, and remove it from the set.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

bool key(pair<long long, long long> a, pair<long long, long long> b){
    return a.second < b.second;
}

int main(){
    long long n, m;
    cin >> n >> m;
    multiset<long long> h;
    vector<long long> t(m);
    for (int i=0;i<n;i++){
        long long x;
        cin >> x;
        h.insert(x);
    }
    for (int i=0;i<m;i++){
        long long x;
        cin >> x;
        auto it = h.upper_bound(x);
        if (it==h.begin()){
            cout << -1 << endl;
        }
        else{
            it--;
            cout << *it << endl;
            h.erase(it);
        }
    }
}
```
