#include <bits/stdc++.h>
using namespace std;

long long n;

int dvs(int k) {
    int dv = 0;
    for (long long d=1; d*d < k; d++) {
        if (k % d == 0) {
            dv += 1;
        }
    }
    return dv;
}

void solve() {
    cin >> n;

    int sum = 0;
    for (int i=1; i<=n; i++) {
        sum += dvs(i);
    }
    cout << sum << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}