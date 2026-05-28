```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> a(n+1, vector<pair<long long, long long>>());
    for (long long i=0;i<m;i++){
        long long u, v, c;
        cin >> u >> v >> c;
        a[u].push_back({c, v});
    }
    vector<vector<long long>> dist(n+1, vector<long long>(2, LLONG_MAX));
    dist[1][1]=0; //yes discount
    priority_queue<tuple<long long, long long, long long>, vector<tuple<long long, long long, long long>>, greater<tuple<long long, long long, long long>>> pq; // cost, next, 0 is no left, 1 is left
    pq.push({0, 1, 1});
    while (!pq.empty()){
        auto [curr_cost, curr, discount] = pq.top();
        pq.pop();
        if (curr_cost > dist[curr][discount]) continue;
        if (discount==0){
            for (auto [cost, v] : a[curr]){
                if (dist[curr][0] + cost < dist[v][0]){
                    dist[v][0]=dist[curr][0] + cost;
                    pq.push({dist[v][0], v, 0});
                }
            }
        }
        else{
            for (auto [cost, v] : a[curr]){
                if (dist[curr][1] + cost < dist[v][1]){
                    dist[v][1]=dist[curr][1] + cost;
                    pq.push({dist[v][1], v, 1});
                }
                if (dist[curr][1] + cost/2 < dist[v][0]){
                    dist[v][0]=dist[curr][1] + cost/2;
                    pq.push({dist[v][0], v, 0});
                }            
            }          
        }
    }
    cout << dist[n][0] << endl;
}
```
