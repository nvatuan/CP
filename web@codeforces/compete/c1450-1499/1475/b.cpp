#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n; cin >> n;

    long long b = n % 2020;
    if (n / 2020 >= b) {
        cout << "YES\n";   
    } else {
        cout << "NO\n";
    }
    
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}