#include <bits/stdc++.h>
using namespace std;

int main(){
    long long q;
    cin >> q;
    while (q--){
        long long k;
        cin >> k;
        long long idx=1;
        while ((long long)pow(10, idx-1)*9*idx<k){
            k-=idx*9*(long long)pow(10, idx-1);
            idx++;
        }
        long long prev = (long long)pow(10, idx-1);
        long long count = k - 1;
        long long index_of_number = count / idx;
        long long which_digit = count % idx;
        long long num_required = prev + index_of_number;
        string num_string = to_string(num_required);
        cout << num_string[which_digit] << endl;
    }   
}