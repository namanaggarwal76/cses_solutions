#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n%2==0 && ((n*(n+1))/2)%2==0){
        cout << "YES" << endl;
        int l=1;
        int r=n;
        cout << n/2 << endl;
        while (l<r){
            cout << l << " " << r << " ";
            l+=2;
            r-=2;
        }
        cout << endl;
        l=2;
        r=n-1;
        cout << n/2 << " ";
        while (l<r){
            cout << l << " " << r << " ";
            l+=2;
            r-=2;
        }
        cout << endl;
    }
    else if (n%2==1 && ((n*(n+1))/2)%2==0){
        cout << "YES" << endl;
        int l=1;
        int r=n-1;
        cout << n/2 + 1 << endl;
        while (l<r){
            cout << l << " " << r << " ";
            l+=2;
            r-=2;
        }
        l=2;
        r=n-2;
        cout << endl;
        cout << n/2 << " ";
        if (n/2!=1){
            while (l<r){
                cout << l << " " << r << " ";
                l+=2;
                r-=2;
            }
        }
        cout << n << endl;
    }
    else{
        cout << "NO" << endl;
    }
}