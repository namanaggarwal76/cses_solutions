#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    long long x,a,b,c;
    cin >> x >> a >> b >> c;
    vector<long long> arr(n);
    arr[0]=x;
    for (long long i=1;i<n;i++){
        arr[i]=(arr[i-1]*a+b)%c;
    }
    long long l=0, r=0;
    long long ans=0;
    long long res=0;
    while (r<k){
        ans^=arr[r];
        r++;
    }
    res^=ans;
    long long left=arr[0];
    while (r<n){
        ans^=arr[r];
        r++;
        ans^=left;
        l++;
        left=arr[l];
        res^=ans;
    }
    cout << res << endl;
}