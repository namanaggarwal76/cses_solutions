#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> coins(n);
    for (long long i=0;i<n;i++) cin >> coins[i];
    sort(coins.begin(), coins.end());
    long long ans=0;
    for (long long i=0;i<n;i++){
        if (coins[i]>ans+1) break;
        ans+=coins[i];
    }
    cout << ans+1 << endl;
}