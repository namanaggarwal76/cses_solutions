#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> a(n+1, vector<pair<long long, long long>>());
    for (long long i=0;i<m;i++){
        long long u,v,c;
        cin >> u >> v >> c;
        a[u].push_back({c, v});
    }
    vector<long long> parent(n+1, -1);
    vector<long long> dist(n+1, 0);
    // run n times
    for (long long i=1;i<=n;i++){
        for (long long j=1;j<=n;j++){
            for (auto [cost, next] : a[j]){
                if (dist[j] + cost < dist[next]){
                    dist[next] = dist[j] + cost;
                    parent[next] = j;
                    // if in nth iteration there is relaxation, then there is cycle, so starting from next, we move back n times, and then start the path
                    if (i==n){
                        cout << "YES" << endl;
                        long long temp=next;    
                        for (int k=0;k<n;k++){
                            temp = parent[temp];
                        }
                        vector<long long> path;
                        path.push_back(temp);
                        long long start = temp;
                        temp=parent[temp];
                        while (temp!=start){
                            path.push_back(temp);
                            temp = parent[temp];
                        }
                        path.push_back(start);
                        reverse(path.begin(), path.end());
                        for (int i=0;i<path.size();i++){
                            cout << path[i] << " ";
                        }
                        cout << endl;
                        return 0;
                    }
                }
            }
        }   
    }
    cout << "NO" << endl;
}