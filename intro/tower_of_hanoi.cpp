#include <bits/stdc++.h>
using namespace std;

void func(int n, int curr, int final, int help){
    if (n==0) return;
    func(n-1, curr, help, final);
    cout << curr << " "  << final << endl;
    func(n-1, help, final, curr);
}

int main(){
    int n;
    cin >> n;
    cout << (1LL << n) - 1 << endl;
    func(n, 1, 3, 2);
}