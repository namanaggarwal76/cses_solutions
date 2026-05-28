#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int>());
    for (int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<bool> visited(n+1, false);
    vector<int> res;
    for (int i=1;i<=n;i++){
        if (!visited[i]){
            res.push_back(i);
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()){
                int curr = q.front();
                q.pop();
                for (int next : a[curr]){
                    if (!visited[next]){
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
    }
    cout << res.size()-1 << endl;
    for (int i=0;i<res.size()-1;i++){
        cout << res[i] << " " << res[i+1] << endl;
    }
}