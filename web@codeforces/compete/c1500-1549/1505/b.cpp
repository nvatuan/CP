#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    for (int d=1;; d++) {
        if (d*d > n) {
            cout << d-1 << endl;
            return;
        }
    }
}

int main() {
    solve();
}