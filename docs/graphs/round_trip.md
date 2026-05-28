```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
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
    int cycle_start1=-1;
    int cycle_start2=-1;
    int flag=0;
    for (int i=1;i<=n;i++){
        if (dist[i]==-1){
            dist[i]=1;
            parent[i]=-1;
            queue<int> q;
            q.push(i);
            while (!q.empty()){
                int curr = q.front();
                q.pop();
                for (int next : a[curr]){
                    if (dist[next] == -1){
                        dist[next] = dist[curr] + 1;
                        parent[next] = curr;
                        q.push(next);
                    }
                    else if (dist[next]!=-1 && next!=parent[curr]){
                        cycle_start1=curr;
                        cycle_start2=next;
                        flag=1;
                        break;
                    }
                }
                if (flag==1) break;
            }
        }
        if (flag==1) break;
    }
    if (flag==0){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        vector<int> p1, p2;
        while (cycle_start1!=cycle_start2){
            if (dist[cycle_start1]>dist[cycle_start2]){
                p1.push_back(cycle_start1);
                cycle_start1=parent[cycle_start1];
            }
            else if (dist[cycle_start2]>dist[cycle_start1]){
                p2.push_back(cycle_start2);
                cycle_start2=parent[cycle_start2];
            }
            else{
                p1.push_back(cycle_start1);
                p2.push_back(cycle_start2);
                cycle_start1=parent[cycle_start1];
                cycle_start2=parent[cycle_start2];
            }
        }
        cout << 2 + p1.size() + p2.size() << endl;
        cout << cycle_start1 << " ";
        for (int i=p1.size()-1;i>=0;i--){
            cout << p1[i] << " ";
        }
        for (int i=0;i<p2.size();i++){
            cout << p2[i] << " ";
        }
        cout << cycle_start1 << endl;
    }
}
```
