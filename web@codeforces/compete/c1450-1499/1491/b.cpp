#include <bits/stdc++.h>
using namespace std;

int n, u, v;
int a[1000];

int check_connectivity() {
    set<int> s;
    s.insert(a[n-1]);
    for (int row = n-1; row > 0; row--) {
        if (abs(a[row] - a[row-1]) <= 1) {
            s.insert(a[row-1]);
        } else {
            return 0;
        }
    }
    if (s.size() == 1) {
        return 1; // straight;
    }
    if (s.size() >= 2) {
        return 2; // tilted
    }
}

void solve() {
    scanf("%d%d%d", &n, &u, &v);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);

    int conn = check_connectivity();
    if (conn == 0) cout << 0 << '\n';
    else 
    if (conn == 1) cout << min (2*v, v+u) << '\n';
    else cout << min(v, u) << '\n';    
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}