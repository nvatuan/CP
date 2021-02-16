#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    n = n*m;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    int z = count(a.begin(), a.end(), 0);
    int neg = count_if(a.begin(), a.end(), [&](int x)->bool{return x < 0;});
    
    long long sum=0;
    for (int &i : a) {
        i =  abs(i); 
        sum += i;
    }

    if (z) {
        cout << sum << '\n';
    } else {
        if (neg % 2 == 0) {
            cout << sum << '\n';
        } else {
            cout << sum - 2*(*min_element(a.begin(), a.end())) << '\n';
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}