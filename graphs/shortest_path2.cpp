#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> dist(n+1, vector<long long>(n+1, LLONG_MAX));
    for (long long i=0;i<m;i++){
        long long u,v, c;
        cin >> u >> v >> c;
        dist[u][v] = min(dist[u][v], c);
        dist[v][u] = min(dist[v][u], c);
    }
    for (long long i=1;i<=n;i++){
        dist[i][i] = 0;
    }
    for (long long k=1;k<=n;k++){
        for (long long i=1;i<=n;i++){
            for (long long j=1;j<=n;j++){
                if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    while (q--){
        long long u,v;
        cin >> u >> v;
        if (dist[u][v] == LLONG_MAX) cout << -1 << endl;
        else cout << dist[u][v] << endl;
    }
}