#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    vector<int> pos(n+1);
    for (int i=0;i<n;i++) pos[a[i]]=i;
    int res=1;
    for (int i=1;i<n;i++){
        if (pos[i+1]<pos[i]) res++;
    }
    while (m--){
        int x,y;
        cin >> x >> y;
        int val1=a[x-1];
        int val2=a[y-1];
        int count=0;
        set<pair<int,int>> s;
        if ((val1+1)<=n) s.insert({val1+1,val1});
        if ((val2+1)<=n) s.insert({val2+1,val2});
        if ((val1-1)>=1) s.insert({val1,val1-1});
        if ((val2-1)>=1) s.insert({val2,val2-1});
        for (auto p:s){
            int big=p.first;
            int small=p.second;
            if (pos[big]<pos[small]) count++;
        }
        swap(a[x-1],a[y-1]);
        swap(pos[val1],pos[val2]);
        set<pair<int,int>> s2;
        if ((val1+1)<=n) s2.insert({val1+1,val1});
        if ((val2+1)<=n) s2.insert({val2+1,val2});
        if ((val1-1)>=1) s2.insert({val1,val1-1});
        if ((val2-1)>=1) s2.insert({val2,val2-1});
        for (auto p:s2){
            int big=p.first;
            int small=p.second;
            if (pos[big]<pos[small]) count--;
        }       
        res-=count;
        cout << res << endl;
    }
}