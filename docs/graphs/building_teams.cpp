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
    vector<int> colour(n+1, 0);
    for (int i=1;i<=n;i++){
        if (colour[i]==0){
            queue<int> q;
            q.push(i);
            colour[i] = 1;
            while (!q.empty()){
                int curr = q.front();
                q.pop();
                for (int next : a[curr]){
                    if (colour[next] == 0){
                        if (colour[curr] == 1) colour[next] = 2;
                        else colour[next] = 1;  
                        q.push(next);
                    } 
                    else if (colour[next] == colour[curr]){
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout << colour[i] << " ";
    }
    cout << endl;
}