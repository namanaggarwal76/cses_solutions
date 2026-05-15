#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<vector<char>> grid(n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            char c;
            cin >> c;
            grid[i].push_back(c);
        }
    }

    // gives mle for large n, as O(n^3), need to do better

    // vector<vector<string>> dp(n, vector<string>(n, ""));
    // for (int i=n-1;i>=0;i--){
    //     for (int j=n-1;j>=0;j--){
    //         dp[i][j]=grid[i][j];
    //         string s1="";
    //         if (i+1<n) s1+=dp[i+1][j];
    //         string s2="";
    //         if (j+1<n) s2+=dp[i][j+1];
    //         if (s1=="" && s2=="") continue;
    //         else if (s1=="") dp[i][j]+=s2;
    //         else if (s2=="") dp[i][j]+=s1;
    //         else dp[i][j]+=min(s1, s2);
    //     }
    // }
    // cout << dp[0][0] << endl;
}