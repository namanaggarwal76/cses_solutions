#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    vector<pair<long long, long long>> arr;
    for (int i=0;i<n;i++){
        long long a,b;
        cin >> a >> b;
        arr.push_back({a, 1});
        arr.push_back({b, -1});
    }
    sort(arr.begin(), arr.end());
    int count=0;
    int max1=0;
    for (int i=0;i<2*n;i++){
        count+=arr[i].second;
        max1=max(max1, count);
    }
    cout << max1 << endl;
}