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