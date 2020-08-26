#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n; 
    if (n & 1) cout << (n+1)/2 << '\n';
    else cout << (n/2) + 1 << '\n';
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}