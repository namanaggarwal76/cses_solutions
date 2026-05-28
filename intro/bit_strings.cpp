#include <bits/stdc++.h>
using namespace std;

int main(){
    const long long MOD = 1e9 + 7;
    long long n;
    cin >> n;
    long long res=1;
    long long a=2;
    while (n>0){
        if (n&1){
            res=(res*a)%MOD;
        }
        a=(a*a)%MOD;
        n=n>>1;
    }
    cout << res << endl;
}