# Repetitions

## Problem Link

[https://cses.fi/problemset/task/1743](https://cses.fi/problemset/task/1743)

## Complexity

- Time: O(26*26*n)
- Space: O(n)

## Approach

first we count frequency of each character, and the constraint of putting an element is that it should be smallest given that its frequency > 0, and the in the remaining string no element has frequncy > len/2, so we keep checking these and put characters greedily from i = 0 to n.

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin >> s;
    int n=s.size();
    vector<int> freq(26, 0);
    for (auto& c: s) freq[c-'A']++;
    int curr=-1;
    for (int i=0;i<26;i++){
        if (freq[i]>0){
            freq[i]--;
            int max1 = *max_element(freq.begin(), freq.end());
            int remaining = n-1;
            if ((remaining+1)/2>=max1){
                curr=i;
                break;
            }
            freq[i]++;
        }
    }
    s[0]='A'+curr;
    for (int i=1;i<n;i++){
        int flag=0;
        for (int j=0;j<26;j++){
            if (j==curr || freq[j]==0) continue;
            freq[j]--;
            int max1 = *max_element(freq.begin(), freq.end());
            int remaining = n-i-1;
            if ((remaining+1)/2>=max1){
                s[i]='A'+j;
                curr = j;
                flag=1;
                break;
            }
            else{
                freq[j]++;
            }
        }
        if (flag==0){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << s << endl;
}
```
