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
    vector<int> dist(n+1, -1);
    vector<int> parent(n+1, -1);
    dist[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int curr = q.front();
        q.pop();
        for (int next : a[curr]){
            if (dist[next] == -1){
                dist[next] = dist[curr] + 1;
                parent[next] = curr;
                if (next == n){
                    cout << dist[next] << endl;
                    vector<int> path;
                    int curr=n;
                    while (curr!=-1){
                        path.push_back(curr);
                        curr = parent[curr];
                    }
                    for (int i=path.size()-1;i>=0;i--){
                        cout << path[i] << " ";
                    }
                    cout << endl;
                    return 0;
                }
                q.push(next);
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}