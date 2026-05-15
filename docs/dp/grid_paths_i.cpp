#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main(){
    long long n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char> (n, '.'));
    vector<vector<long long>> count(n, vector<long long> (n, 0));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }
    if (grid[n-1][n-1]=='.') count[n-1][n-1]=1;
    for (int i=n-1;i>=0;i--){
        for (int j=n-1;j>=0;j--){
            if (grid[i][j]=='*') continue;
            if (i+1<n ) count[i][j]=(count[i][j]+count[i+1][j])%MOD;
            if (j+1<n) count[i][j]=(count[i][j]+count[i][j+1])%MOD;
        }
    }
    cout << count[0][0] << endl;
}