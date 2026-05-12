#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long a,b;
        cin >> a >> b;
        if ((a-2*b)%3 == 0 and a-2*b <= 0 and (b-2*a)%3 == 0 and b-2*a <= 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}