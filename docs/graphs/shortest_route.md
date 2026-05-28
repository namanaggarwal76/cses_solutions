```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> a(n+1, vector<pair<long long, long long>>());
    for (long long i=0;i<m;i++){
        long long u,v,c;
        cin >> u >> v >> c;
        a[u].push_back({c,v});
    }
    vector<long long> dist(n+1, LLONG_MAX);
    dist[1]=0;
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
    pq.push({0,1});
    while (!pq.empty()){
        auto [curr_dist, curr] = pq.top();
        pq.pop();
        if (curr_dist > dist[curr]) continue;
        for (auto [cost, next] : a[curr]){
            if (curr_dist + cost < dist[next]){
                dist[next] = curr_dist + cost;
                pq.push({dist[next], next});
            }
        }
    }
    for (long long i=1;i<=n;i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}
```
