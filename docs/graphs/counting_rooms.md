```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    int count=0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (grid[i][j] == '.' && !visited[i][j]){
                count++;
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = true;
                while (!q.empty()){
                    auto [x,y] = q.front();
                    q.pop();
                    if (x+1 < n && grid[x+1][y] == '.' && !visited[x+1][y]){
                        visited[x+1][y] = true;
                        q.push({x+1,y});
                    }
                    if (y+1 < m && grid[x][y+1] == '.' && !visited[x][y+1]){
                        visited[x][y+1] = true;
                        q.push({x,y+1});
                    }
                    if (x-1 >= 0 && grid[x-1][y] == '.' && !visited[x-1][y]){
                        visited[x-1][y] = true;
                        q.push({x-1,y});
                    }
                    if (y-1 >= 0 && grid[x][y-1] == '.' && !visited[x][y-1]){
                        visited[x][y-1] = true;
                        q.push({x,y-1});
                    }
                }
            }
        }
    }
    cout << count << endl;
}
```
