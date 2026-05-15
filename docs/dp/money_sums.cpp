#include <bits/stdc++.h> 
using namespace std;

const long long MOD = 1e9 + 7;

int main(){
    long long n;
    cin >> n;
    vector<long long> dp(100001, 0);
    vector<long long> coins;
    for (int i=0;i<n;i++){
        long long x;
        cin >> x;
        coins.push_back(x);
    }
    dp[0]=1;
    for (auto& val: coins){
        for (int i=100000;i>0;i--){
            if (i-val>=0) dp[i]=(dp[i]+dp[i-val])%MOD;
        }
    }
    long long res=0;
    for (int i=1;i<=100000;i++) if (dp[i]>0) res++;
    cout << res << endl;
    for (int i=1;i<=100000;i++) if (dp[i]>0) cout << i << " ";
    cout << endl;
}