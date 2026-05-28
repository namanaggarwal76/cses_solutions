#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main(){
    long long t;
    cin >> t;
    vector<vector<long long>> dp(1000001, vector<long long>(2, 0));
    dp[1][0]=1; dp[1][1]=1;
    for (int i=2;i<=1000000;i++){
        dp[i][0]=(2*dp[i-1][0]+dp[i-1][1])%MOD;
        dp[i][1]=(4*dp[i-1][1]+dp[i-1][0])%MOD;
    }
    while (t--){
        long long q;
        cin >> q;
        cout << (dp[q][0] + dp[q][1])%MOD << endl;
    }
}