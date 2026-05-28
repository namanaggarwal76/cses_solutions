#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> a(n+1, vector<pair<long long, long long>>());
    vector<vector<pair<long long, long long>>> a2(n+1, vector<pair<long long, long long>>());
    for (long long i=0;i<m;i++){
        long long u,v,c;
        cin >> u >> v >> c;
        a[u].push_back({c, v});
        a2[v].push_back({c, u});
    }
    vector<bool> canreach(n+1, false);
    canreach[n] = true;
    queue<long long> q;
    q.push(n);
    while (!q.empty()){
        long long curr = q.front();
        q.pop();
        for (auto [cost, next] : a2[curr]){
            if (!canreach[next]){
                canreach[next] = true;
                q.push(next);
            }
        }
    }
    vector<long long> dist(n+1, LLONG_MIN);
    dist[1] = 0;
    for (long long i=1;i<=n;i++){
        for (long long j=1;j<=n;j++){
            for (auto [cost, next] : a[j]){
                if (dist[j] != LLONG_MIN && dist[j] + cost > dist[next]){
                    dist[next] = dist[j] + cost;
                    if (i==n && canreach[next]){
                        cout << -1 << endl;
                        return 0;
                    }
                }
            }
        }   
    }
    cout << dist[n] << endl;
}