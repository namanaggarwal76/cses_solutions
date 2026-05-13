# Digit Queries

## Problem Link

[https://cses.fi/problemset/task/2431/](https://cses.fi/problemset/task/2431/)

## Complexity

- Time: O(log k) per test case   `# base 10`
- Space: O(1)

## Approach

Single digit have 9 numbers, double have 90, triple have 900, so general formula becomes `i * 9 * 10^(i-1)`

now summation from i=0, to i=n  then we find the first n such that `sum >= query`, then find sum till n-1, then find exact number, and then exact digit.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long q;
    cin >> q;
    while (q--){
        long long k;
        cin >> k;
        long long idx=1;
        while ((long long)pow(10, idx-1)*9*idx<k){
            k-=idx*9*(long long)pow(10, idx-1);
            idx++;
        }
        long long prev = (long long)pow(10, idx-1);
        long long count = k - 1;
        long long index_of_number = count / idx;
        long long which_digit = count % idx;
        long long num_required = prev + index_of_number;
        string num_string = to_string(num_required);
        cout << num_string[which_digit] << endl;
    }   
}
```
