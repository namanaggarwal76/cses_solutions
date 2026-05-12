# Missing Number

## Problem Link

[https://cses.fi/problemset/task/1755](https://cses.fi/problemset/task/1755)

## Complexity

- Time: O(n)
- Space: O(n)

## Approach

we count frequncy of all characters, and check if there are >1 characters with odd frequency, if no then we put each character one by one in palindromic terms like one at first, then last and so on, and in the end we put the odd frequency character (if any), in the middle.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    long long n=s.size();
    vector<int> freq(26, 0);
    for (char c:s){
        freq[c-'A']++;
    }
    int count=0;
    int idx=-1;
    for (int i=0;i<26;i++){
        if (freq[i]%2==1){
            count++;
            idx=i;
        }
    }
    int curr=0;
    if (count>1) cout << "NO SOLUTION" << endl;
    else{
        for (int i=0;i<26;i++){
            int a=freq[i];
            if (a%2==0){
                while (a){
                    s[curr]='A'+i;
                    s[n-1-curr]='A'+i;
                    curr++;
                    a=a-2;
                }
            }
        }
        if (idx!=-1){
            int a=freq[idx];
            while (a){
                s[curr]='A'+idx;
                a--;
                curr++;
            }
        }
        cout << s << endl;
    }
}
```
