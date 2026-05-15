#include <bits/stdc++.h> 
using namespace std;

int main(){
    long long n,target;
    cin >> n >> target;
    vector<long long> dp(1000001, LLONG_MAX);
    vector<long long> coins;
    for (int i=0;i<n;i++){
        long long x;
        cin >> x;
        coins.push_back(x);
        dp[x]=1;
    }
    for (int i=0;i<=1000000;i++){
        for (auto& val: coins){
            if (i-val>=0 && dp[i-val]!=LLONG_MAX) dp[i]=min(dp[i], dp[i-val]+1);
        }
    }
    if (dp[target]==LLONG_MAX) cout << -1 << endl;
    else cout << dp[target] << endl;
}
