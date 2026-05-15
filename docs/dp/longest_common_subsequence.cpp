
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++) cin >> b[i];
    vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
    for (int i=1;i<=n;i++){
        if (a[i-1]==b[0]) dp[i][1]=1;
        else dp[i][1]=dp[i-1][1];
    }
    for (int i=1;i<=m;i++){
        if (a[0]==b[i-1]) dp[1][i]=1;
        else dp[1][i]=dp[1][i-1];
    }
    for (int i=2;i<=n;i++){
        for (int j=2;j<=m;j++){
            if (a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    vector<long long> res;
    int i=n;
    int j=m;
    while (i>0 && j>0){
        if (a[i-1]==b[j-1]){
            res.push_back(a[i-1]);
            i--;
            j--;
        }
        else if (dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    reverse(res.begin(), res.end());
    cout << dp[n][m] << endl;
    for (auto x: res) cout << x << " ";
}