#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;
    cin >> n >> m;
    vector<vector<long long>> dp(n+1, vector<long long>(m+1, LLONG_MAX));
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            if (i==j) dp[i][j]=0;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (i==j) continue;
            for (int k=1;k<i;k++){
                dp[i][j]=min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            }
            for (int k=1;k<j;k++){
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
            }
        }
    }
    cout << dp[n][m] << endl;
}