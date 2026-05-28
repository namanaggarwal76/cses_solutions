#include <bits/stdc++.h>
using namespace std;

vector<long long> fun(long long num){
    vector<long long> res;
    while (num!=0){
        res.push_back(num%10);
        num/=10;
    }
    return res;
}

int main(){
    long long n;
    cin >> n;
    vector<long long> dp(1000001,LLONG_MAX);
    dp[0]=0; // base case
    for (int i=1;i<=1000000;i++){
        vector<long long> digits = fun(i);
        for (auto& digit: digits){
            if (i-digit>=0 && digit!=0) dp[i]=min(dp[i],dp[i-digit]+1);
        }
    }
    cout << dp[n] << endl;
}