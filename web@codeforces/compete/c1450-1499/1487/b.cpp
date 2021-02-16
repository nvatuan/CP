#include <bits/stdc++.h>
using namespace std;

int n, k;

void solve() {
    cin >> n >> k;
    if (n % 2 == 0) {
        k--;
        cout << (k % n) + 1 << endl;
    } else {
        k--;
        int change_spot = k / ((n-1)/2);
        cout << ((k + change_spot) % n) + 1 << endl;
    }
    
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}