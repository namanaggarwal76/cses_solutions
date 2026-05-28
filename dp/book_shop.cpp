#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;
    vector<long long> price(n);
    vector<long long> pages(n);
    for (int i=0;i<n;i++) cin >> price[i];
    for (int i=0;i<n;i++) cin >> pages[i];

    // this is also a valid sol, but is a 2d dp so gives MLE (rte) in CSES

    // vector<vector<long long>> dp(x+1, vector<long long>(n, 0));
    // for (int i=1;i<=x;i++){
    //     if (i>=price[0]) dp[i][0]=pages[0];
    // }
    // for (int j=1;j<n;j++){
    //     for (int i=1;i<=x;i++){
    //         dp[i][j]=dp[i][j-1];
    //         if (i-price[j]>=0) dp[i][j]=max(dp[i-price[j]][j-1]+pages[j],dp[i][j-1]);
    //     }
    // }
    // cout << dp[x][n-1] << endl;


    vector<long long> dp(x+1, 0);
    for (int j=0;j<n;j++){
        for (int i=x;i>0;i--){
            if (i-price[j]>=0) dp[i]=max(dp[i-price[j]]+pages[j], dp[i]);
        }
    }
    cout << dp[x] << endl;
}