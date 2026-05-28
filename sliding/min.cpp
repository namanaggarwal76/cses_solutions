#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long n,k;
    cin >> n >> k;
    long long x,a,b,c;
    cin >> x >> a >> b >> c;
    vector<long long> arr(n);
    arr[0]=x;
    for (int i=1;i<n;i++){
        arr[i]=(arr[i-1]*a+b)%c;
    }
    int l=0, r=0;
    deque<pair<long long, long long>> dq;
    while (r<k){
        while (!dq.empty() && dq.back().first>=arr[r]) dq.pop_back();
        dq.push_back({arr[r], r});
        r++;
    }
    long long ans=dq.front().first;
    while (r<n){
        while (!dq.empty() && dq.back().first>=arr[r]) dq.pop_back();
        dq.push_back({arr[r], r});
        while (dq.front().second<=r-k) dq.pop_front();
        ans^=dq.front().first;
        r++;
        l++;
    }
    cout << ans << endl;
}