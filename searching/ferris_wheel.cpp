#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    int l=0;
    int r=n-1;
    int res=0;
    while (l<r){
        if (a[l]+a[r]>x){
            res++;
            r--;
        }
        else{
            res++;
            r--;
            l++;
        }
    }
    if (l==r) res++;
    cout << res << endl;
}