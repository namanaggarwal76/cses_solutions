#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<pair<int,int>> monsters;
    pair<int,int> start;
    vector<pair<int,int>> ends;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
            if (grid[i][j] == 'M') monsters.push_back({i,j});
            if (grid[i][j] == 'A') start = {i,j};
            if ((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]=='.') ends.push_back({i,j});
        }
    }
    if (start.first==0 || start.first==n-1 || start.second==0 || start.second==m-1){
        cout << "YES" << endl;
        cout << 0 << endl;
        cout << endl;
        return 0;
    }
    vector<vector<bool>> monster_visited(n, vector<bool>(m, false));
    vector<vector<int>> monster_dist(n, vector<int>(m, -1));
    queue<pair<int,int>> monster_q;
    for (auto monster: monsters){
        monster_visited[monster.first][monster.second] = true;
        monster_dist[monster.first][monster.second] = 0;
        monster_q.push(monster);
    }
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    while (!monster_q.empty()){
        auto [x,y] = monster_q.front();
        monster_q.pop();
        for (auto [dx,dy] : directions){
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && !monster_visited[nx][ny]){
                monster_visited[nx][ny] = true;
                monster_dist[nx][ny] = monster_dist[x][y] + 1;
                monster_q.push({nx, ny});
            }
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<char>> parent(n, vector<char>(m, '#'));
    queue<pair<int,int>> q;
    visited[start.first][start.second] = true;
    dist[start.first][start.second] = 0;
    q.push(start);
    while (!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for (auto [dx,dy] : directions){
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && !visited[nx][ny] && (monster_dist[nx][ny]>dist[x][y]+1 || monster_dist[nx][ny]==-1)){
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                if (dx==1 && dy==0) parent[nx][ny] = 'D';
                if (dx==-1 && dy==0) parent[nx][ny] = 'U';
                if (dx==0 && dy==1) parent[nx][ny] = 'R';
                if (dx==0 && dy==-1) parent[nx][ny] = 'L';
                q.push({nx, ny});
                if (nx==0 || nx==n-1 || ny==0 || ny==m-1){
                    cout << "YES" << endl;
                    cout << dist[nx][ny] << endl;
                    string path;
                    pair<int,int> curr = {nx, ny};
                    while (curr != start){
                        char dir = parent[curr.first][curr.second];
                        path += dir;
                        if (dir == 'D') curr.first--;
                        if (dir == 'U') curr.first++;
                        if (dir == 'R') curr.second--;
                        if (dir == 'L') curr.second++;
                    }
                    reverse(path.begin(), path.end());
                    cout << path << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
}
