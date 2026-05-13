#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<vector<long long>> dist(n, vector<long long>(n, 0));
    vector<vector<long long>> visited(n, vector<long long>(n, 0));
    dist[0][0]=0;
    visited[0][0]=1;
    queue<pair<int, int>> q;
    vector<pair<int, int>> moves = {{-2, -1}, {-2, +1}, {-1, -2}, {-1, +2}, {+1, -2}, {+1, +2}, {+2, -1}, {+2, +1}};
    q.push({0,0});
    while (!q.empty()){
        int x_curr=q.front().first;
        int y_curr=q.front().second;
        int dist_curr=dist[x_curr][y_curr];
        q.pop();
        for (auto &m : moves) {
            int nx = x_curr + m.first;
            int ny = y_curr + m.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny]==0){
                visited[nx][ny]=1;
                dist[nx][ny] = dist_curr + 1;
                q.push({nx, ny});
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}