# Grid Paths I

## Problem Link

[https://cses.fi/problemset/task/1638](https://cses.fi/problemset/task/1638)

## Complexity

- Time: O(n^2)
- Space: O(n^2)
  
## Approach

As we can only move right or down, current ans depends on the ans of the cell to the right and the cell below. So we can use a 2D dp array where `dp[i][j]` is the number of paths from (i, j) to (n-1, n-1). We can fill this dp array in a bottom-up manner starting from (n-1, n-1) and moving towards (0, 0). Initially we set all counts to 0, and `count[n-1][n-1]` is set to 1 if the cell is not blocked, else it remains 0. Then for each cell, if it's not blocked, we add the counts from the right and down cells to get the count for the current cell. Finally, `dp[0][0]` will give us the number of paths from (0, 0) to (n-1, n-1).

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main(){
    long long n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char> (n, '.'));
    vector<vector<long long>> count(n, vector<long long> (n, 0));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }
    if (grid[n-1][n-1]=='.') count[n-1][n-1]=1;
    for (int i=n-1;i>=0;i--){
        for (int j=n-1;j>=0;j--){
            if (grid[i][j]=='*') continue;
            if (i+1<n ) count[i][j]=(count[i][j]+count[i+1][j])%MOD;
            if (j+1<n) count[i][j]=(count[i][j]+count[i][j+1])%MOD;
        }
    }
    cout << count[0][0] << endl;
}
```
