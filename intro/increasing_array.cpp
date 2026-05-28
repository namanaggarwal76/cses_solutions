#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i=0;i<n;i++){
        cin >> a[i];
    }
    long long curr=a[0];
    long long res=0;
    for (long long i=1;i<n;i++){
        if (a[i]<curr) res+=curr-a[i];
        else curr=a[i];
    }
    cout << res << endl;
}