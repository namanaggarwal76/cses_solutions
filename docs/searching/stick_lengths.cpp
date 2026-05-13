#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    if (n%2==0){
        long long res1=0;
        for (int i=0;i<n;i++){
            res1+=abs(a[i]-a[n/2]);
        }
        long long res2=0;
        for (int i=0;i<n;i++){
            res2+=abs(a[i]-a[n/2 - 1]);
        }
        cout << min(res1, res2) << endl;
    }
    else{
        long long res1=0;
        for (int i=0;i<n;i++){
            res1+=abs(a[i]-a[n/2]);
        }
        cout << res1 << endl;    
    }
}