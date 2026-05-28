#include <bits/stdc++.h>
using namespace std;

bool check(string s, int idx, unordered_set<string>& visited){
    if (s[idx]=='0') s[idx]='1';
    else s[idx]='0';
    if (visited.count(s)) return true;
    return false;
}

int main(){
    long long n;
    cin >> n;
    unordered_set<string> visited;
    string s(n, '0');
    long long count=1;
    int idx=n-1;
    cout << s << endl;
    visited.insert(s);
    long long total=pow(2, n);
    while (count<total){
        if (check(s, idx, visited)){
            idx--;
            if (idx<0) idx=n-1;
        }
        else{
            if (s[idx]=='0') s[idx]='1';
            else s[idx]='0'; 
            cout << s << endl;
            visited.insert(s);
            idx=n-1;       
            count++;   
        }
    }
}