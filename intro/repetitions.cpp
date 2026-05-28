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