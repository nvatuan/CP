#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (i*i == n) {
                cout << i << '\n';
            } else {
                cout << i << '\n';
            }
            return;
        }
    }
    cout << n-1 << '\n';
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}