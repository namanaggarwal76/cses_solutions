#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    set<int> s;
    int l=0, r=0, max1=-1, len=-1;
    while (r<n){
        if (s.find(a[r])==s.end()){
            s.insert(a[r]);
            len=r-l+1;
            max1=max(max1, len);
            r++;
        }
        else{
            s.erase(a[l]);
            l++;
        }
    }
    cout << max1 << endl;
}