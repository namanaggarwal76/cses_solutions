#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pos(n+1);
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) pos[a[i]]=i;
    int res=0;
    for (int i=1;i<n;i++){
        if (pos[i+1]<pos[i]) res++;
    }
    cout << res+1 << endl;
}