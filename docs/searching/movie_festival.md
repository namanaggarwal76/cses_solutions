# Movie Festival

## Problem Link

[https://cses.fi/problemset/task/1629/](https://cses.fi/problemset/task/1629/)

## Complexity

- Time: O(n logn)
- Space: O(n)

## Approach

So we sort by ending time in ascending, and choose the early ending films greedily so as to maximise the overall count.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

bool key(pair<long long, long long> a, pair<long long, long long> b){
    return a.second < b.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<long long, long long>> arr;
    for (int i=0;i<n;i++){
        long long a,b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end(), key);
    int idx=0;
    int count=1;
    int curr=idx;
    idx++;
    while (idx<n){
        if (arr[idx].first>=arr[curr].second){
            count++;
            curr=idx;
        }
        idx++;
    }
    cout << count << endl;
}
```
