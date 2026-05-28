#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    pair<int,int> start, end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i,j};
            if (grid[i][j] == 'B') end = {i,j};
        }
    }
    vector<vector<char>> visited(n, vector<char>(m, '#'));
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = 'X';
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    while (!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for (auto [dx,dy] : directions){
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && visited[nx][ny] == '#'){
                if (dx==1 && dy==0) visited[nx][ny] = 'D';
                if (dx==-1 && dy==0) visited[nx][ny] = 'U';
                if (dx==0 && dy==1) visited[nx][ny] = 'R';
                if (dx==0 && dy==-1) visited[nx][ny] = 'L';
                if (nx==end.first && ny==end.second){
                    cout << "YES" << endl;
                    string path;
                    pair<int,int> curr = end;
                    while (curr != start){
                        char dir = visited[curr.first][curr.second];
                        path += dir;
                        if (dir == 'D') curr.first--;
                        if (dir == 'U') curr.first++;
                        if (dir == 'R') curr.second--;
                        if (dir == 'L') curr.second++;
                    }
                    reverse(path.begin(), path.end());
                    cout << path.size() << endl;
                    cout << path << endl;
                    return 0;
                }
                q.push({nx, ny});
            } 
        }
    }
    cout << "NO" << endl;
}