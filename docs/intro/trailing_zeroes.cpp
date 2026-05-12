#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    int a=0, b=0;
    int curr=5;
    while (n/curr){
        a+=n/curr;
        curr*=5;
    }
    curr=2;
    while (n/curr){
        b+=n/curr;
        curr*=2;
    }
    cout << min(a,b) << endl;
}