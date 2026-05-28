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
    long long sum=0;
    long long ans=0;
    while (r<k){
        sum+=arr[r];
        r++;
    }
    ans=sum;
    while (r<n){
        sum+=arr[r];
        sum-=arr[l];
        ans=ans^sum;
        l++;
        r++;
    }
    cout << ans << endl;
}