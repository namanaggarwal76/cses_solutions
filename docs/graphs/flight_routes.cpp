#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<long long, long long>>> a(n+1, vector<pair<long long, long long>>());
    for (int i=0;i<m;i++){
        long long u, v, c;
        cin >> u >> v >> c;
        a[u].push_back({c, v});
    }
    vector<int> visited(n+1, 0);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0,1});
    vector<long long> res;
    while (!pq.empty()){
        auto [curr_cost, curr] = pq.top();
        pq.pop();
        if (visited[curr]>=k) continue;
        visited[curr]++;
        if (curr==n) res.push_back(curr_cost);
        for (auto [cost, v] : a[curr]){
            pq.push({curr_cost+cost, v});
        } 
    }
    for (auto x : res){
        cout << x << " ";
    }
    cout << endl;
}