# Dice Combinations

## Problem Link

[https://cses.fi/problemset/task/1633](https://cses.fi/problemset/task/1633)

## Complexity

- Time Complexity: O(n)
- Space Complexity: O(n)

## Approach

for 1-6, we can directly roll the dice, or we can roll some smaller number, so we add from i-1 to 1, and for larger numbers, we only add from i-1 to i-6, and we can use a dp array to store the number of ways to get to each number.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main(){
    long long n;
    cin >> n;
    vector<long long> dp(1000001, 0);
    dp[0]=0;
    for (int i=1;i<=1000000;i++){
        for (int j=i-1;j>=max(i-6,1);j--){
            dp[i]=(dp[i]+dp[j])%MOD;
        }
        if (i<=6) dp[i]+=1;
    }
    cout << dp[n] << endl;
}
```
