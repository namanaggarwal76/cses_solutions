#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1);
    vector<int> in(n+1, 0);
    for (int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        in[v]++;
    }
    queue<int> q;
    vector<int> res;
    for (int i=1;i<=n;i++){
        if (in[i]==0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int curr=q.front();
        q.pop();
        res.push_back(curr);
        for (auto v : a[curr]){
            in[v]--;
            if (in[v]==0) q.push(v);
        }
    }
    if (res.size()==n){
        for (auto x: res){
            cout << x << " ";
            cout << endl;
        }
    }
    else cout << "IMPOSSIBLE" << endl;
}