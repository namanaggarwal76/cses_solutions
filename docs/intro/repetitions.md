# Repetitions

## Problem Link

[https://cses.fi/problemset/task/1069](https://cses.fi/problemset/task/1069)

## Complexity

- Time: O(n)
- Space: O(n)

## Approach

We keep track of length of the current same character sequence, and update max length accordingly, and if a new sequence starts we make current length = 0 again and do it for the entire string.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n=s.size();
    int curr=s[0];
    int curr_len=1;
    int max_len=1;
    for (int i=1;i<n;i++){
        if (s[i]==curr){
            curr_len++;
            max_len=max(max_len, curr_len);
        }
        else{
            curr=s[i];
            curr_len=1;
        }
    }
    cout << max_len << endl;
}
```
