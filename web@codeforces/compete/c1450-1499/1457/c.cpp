#include <bits/stdc++.h>
using namespace std;

int n, p, k;
int a[(int)1e6];
string s;
long long x, y;

vector<pair<int, long long>> G[(int)1e6];
long long costReach[(int)1e6];

void solve() {
    cin >> n >> p >> k;
    for (int i=1; i<=n; i++) {
        char c; cin >> c;
        a[i] = (c != '1');
    }
    cin >> x >> y;

    //
    for (int i=1; i<=n; i++) {
        if (i >= p) costReach[i] = y*(i-p) + x*a[i];
    }

    long long ans = LLONG_MAX;
    for (int i=p; i<=n; i++) {
        if (i + k > n) ans = min(ans, costReach[i]);
        else {
            costReach[i+k] = min(costReach[i+k], costReach[i] + a[i+k]*x);
        }
    }
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}