#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1000];

void solve() {
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> a[i];
    if (k==1) {
        if (std::count(a, a+n, a[0]) == n) {
            cout << 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    } else {
        set<int> s; s.insert(a[0]);
        int ans = 1;
        for (int i=0; i<n; i++) {
            if (s.find(a[i]) == s.end()) {
                if (s.size() == k) {
                    ans++;
                    s.clear();
                    s.insert(a[i-1]);
                }
                s.insert(a[i]);
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();    
}