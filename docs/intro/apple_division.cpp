#include <bits/stdc++.h>
using namespace std;

long long max1;

long long fun(vector<long long>& a, long long sum_final, long long i, long long total){
    if (i==a.size()) return abs(total - 2*sum_final);
    long long sum1=fun(a, sum_final+a[i], i+1, total);
    long long sum2=fun(a, sum_final, i+1, total);
    max1=min(sum1, sum2);
    return max1;
}

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long total=0;
    for (long long i=0;i<n;i++){
        cin >> a[i];
        total+=a[i];
    }
    cout << fun(a, 0, 0, total) << endl;
}