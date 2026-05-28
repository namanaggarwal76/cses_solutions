#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> towers;
    while (n--){
        int x;
        cin >> x;
        auto it=upper_bound(towers.begin(), towers.end(), x);
        if (it==towers.end()) towers.push_back(x);
        else towers[it-towers.begin()]=x;
    }
    cout << towers.size() << endl;
}