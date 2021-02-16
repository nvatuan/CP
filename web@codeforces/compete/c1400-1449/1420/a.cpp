#include <bits/stdc++.h>
using namespace std;

int n;
int a[200010], s[200010];

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) { cin >> a[i]; s[i] = a[i]; }
    sort(s, s + n, greater<int>());
    
    bool flag = true;
    for (int i=0; i<n; i++) flag &= (s[i] == a[i]);
    map<int, int> m;
    for (int i=0; i<n; i++) {
        flag &= (m[a[i]] == 0);
        m[a[i]] = 1;
    }
    cout << (flag ? "NO\n" : "YES\n");
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}