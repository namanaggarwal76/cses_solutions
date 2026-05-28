#include <bits/stdc++.h>
using namespace std;

int main(){
    long long k;
    cin >> k;
    if (k>=1) cout << 0 << endl;
    if (k>=2) cout << 6 << endl;
    if (k>=3) cout << 28 << endl;
    for (long long i=4;i<=k;i++){
        cout << ((i-4)*(i-4)*(i*i - 9) + 4*(i*i - 3) + 8*(i*i - 4) + (i*i - 5)*(i-4)*4 + 4*(i*i-5) + (i*i - 7)*(i-4)*4)/2 << endl;
    }
}