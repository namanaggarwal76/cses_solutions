```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<long long>> a;
vector<int> state;
vector<int> parent;
vector<int> cycle;

bool dfs(int u){
    state[u]=1;
    for (auto v : a[u]){
        if (state[v]==0){
            parent[v]=u;
            if (dfs(v)) return true;
        }
        else if (state[v]==1){
            cycle.push_back(v);
            while (v!=u){
                cycle.push_back(u);
                u=parent[u];
            }
            cycle.push_back(u);
            reverse(cycle.begin(), cycle.end());
            return true;
        }
    }
    state[u]=2;
    return false;
}

int main(){
    cin >> n >> m;
    a.resize(n + 1);
    state.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    for (int i=0;i<m;i++){
        long long u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    for (int i=1;i<=n;i++){ 
        if (dfs(i)){
            cout << cycle.size() << endl;
            for (auto x: cycle){
                cout << x << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
```
