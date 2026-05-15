#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main(){
    long long n;
    cin >> n;
    vector<long long> dp(1000001, 0);
    dp[0]=0;
    for (int i=1;i<=1000000;i++){
        for (int j=i-1;j>=max(i-6,1);j--){
            dp[i]=(dp[i]+dp[j])%MOD;
        }
        if (i<=6) dp[i]+=1;
    }
    cout << dp[n] << endl;
}
