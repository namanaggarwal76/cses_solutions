# Two Sets

## Problem Link

[https://cses.fi/problemset/task/1092](https://cses.fi/problemset/task/1092)

## Complexity

- Time: O(n)
- Space: O(1)

## Approach

If n is even and n/2 is also even, then we have something like

```bash
1 2 3 4 ... n
```
and there are n/2 even numbers, and n/2 odd numbers. Total sum is even. So me pair first and last elements in alternate sets. For example -->

```bash
1 2 3 4 
1 and 4 in set 1
2 and 3 in set 2
```

Now when n is even but n/2 is odd, we have odd count of odd numbers, so overall their sum will be odd, and total sum will be odd, so no solution.

3rd Case, when n is odd, and sum is even, this will have even number of odd numbers, and odd number of evens.
random idea (works!!) : pick 1 and second last in set1, and last in set2, and then do the first and last in alternate sets.

```bash
1 2 3 ......  n-1 n
Set1 : 1 n-1 2 n-2 ....
Set2 : n 3 n-3 ....
```

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n%2==0 && ((n*(n+1))/2)%2==0){
        cout << "YES" << endl;
        int l=1;
        int r=n;
        cout << n/2 << endl;
        while (l<r){
            cout << l << " " << r << " ";
            l+=2;
            r-=2;
        }
        cout << endl;
        l=2;
        r=n-1;
        cout << n/2 << " ";
        while (l<r){
            cout << l << " " << r << " ";
            l+=2;
            r-=2;
        }
        cout << endl;
    }
    else if (n%2==1 && ((n*(n+1))/2)%2==0){
        cout << "YES" << endl;
        int l=1;
        int r=n-1;
        cout << n/2 + 1 << endl;
        while (l<r){
            cout << l << " " << r << " ";
            l+=2;
            r-=2;
        }
        l=2;
        r=n-2;
        cout << endl;
        cout << n/2 << " ";
        if (n/2!=1){
            while (l<r){
                cout << l << " " << r << " ";
                l+=2;
                r-=2;
            }
        }
        cout << n << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
```
