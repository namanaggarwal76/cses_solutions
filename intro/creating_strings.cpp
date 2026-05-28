#include <bits/stdc++.h>
using namespace std;

void rev(string& s, int a, int b){
    for (int i=a;i<=(a+b)/2; i++){
        swap(s[i], s[a+b-i]);
    }
}

int main(){
    string s;
    cin >> s;
    long long n=s.size();
    vector<long long> fact(21, 1);
    vector<long long> freq(27, 0);
    for (int i=1;i<=20;i++) fact[i]=i*fact[i-1];
    for (auto& c: s) freq[c-'a']++;
    long long count = fact[n];
    for (int i=0;i<26;i++) count/=fact[freq[i]];
    cout << count << endl;
    sort(s.begin(), s.end());
    while (true){
        cout << s << endl;
        int idx=-1;
        for (int i=n-2;i>=0;i--){
            if (s[i]<s[i+1]){
                idx=i;
                break;
            }
        }
        if (idx==-1) break;
        int small;
        for (int j=n-1;j>idx;j--){
            if (s[j]>s[idx]){
                small=j;
                break;
            }
        }
        swap(s[idx], s[small]);
        rev(s, idx+1, n-1);
    }
}
