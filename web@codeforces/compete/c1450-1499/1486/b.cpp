#include <bits/stdc++.h>
using namespace std;

int n;
int x[10000], y[10000];

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x, x+n);
    sort(y, y+n);
    
    if (n % 2 == 1) {
        cout << 1 << '\n';
    } else {
        int med=n/2-1;
        int med2=n/2;
        cout << 1LL * (x[med2] - x[med] + 1) * (y[med2] - y[med] + 1) << '\n';
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}