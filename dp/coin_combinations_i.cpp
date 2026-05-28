#include <bits/stdc++.h> 
using namespace std;

const long long MOD = 1e9 + 7;

int main(){
    long long n,target;
    cin >> n >> target;
    vector<long long> dp(1000001, 0);
    vector<long long> coins;
    for (int i=0;i<n;i++){
        long long x;
        cin >> x;
        coins.push_back(x);
        dp[x]=1;
    }
    for (int i=0;i<=1000000;i++){
        for (auto& val: coins){
            if (i-val>=0) dp[i]=(dp[i]+dp[i-val])%MOD;
        }
    }
    cout << dp[target] << endl;
}
