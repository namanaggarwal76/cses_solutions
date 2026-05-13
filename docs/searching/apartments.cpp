#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    vector<pair<long long,long long>> a;
    vector<long long> b;
    cin >> n >> m >> k;
    for (int i=0;i<n;i++){
        long long x;
        cin >> x;
        a.push_back({x-k, x+k});
    }
    for (int i=0;i<m;i++){
        long long x;
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    int idx=0;
    for (int i=0;i<n;i++){
        while (idx<m && b[idx]<a[i].first) idx++;
        if (idx<m && b[idx]<=a[i].second){
            ans++;
            idx++;
        }
    }
    cout << ans << endl;
}