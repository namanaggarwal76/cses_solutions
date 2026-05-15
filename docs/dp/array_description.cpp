#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main(){
    long long n,m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    vector<vector<long long>> dp(n, vector<long long>(m+1, 0));
    if (a[0]==0){
        for (int x=1;x<=m;x++) {
            dp[0][x]=1;
        }
    }
    else dp[0][a[0]] = 1;
    for (int i=1;i<n;i++){
        for (int j=1;j<=m;j++){
            if (a[i]!=0 && j!=a[i]) continue;
            if (i-1>=0 && j-1>=0) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%MOD;
            if (i-1>=0) dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            if (i-1>=0 && j+1<=m) dp[i][j]=(dp[i][j]+dp[i-1][j+1])%MOD;
        }
    }
    long long sum1=0;
    for (int i=1;i<=m;i++) sum1=(sum1+dp[n-1][i])%MOD;
    cout << sum1 << endl;
}
