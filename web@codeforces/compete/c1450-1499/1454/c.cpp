#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<int> b;
    b.push_back(a[0]);
    for (int i=1; i<n; i++)
        if (a[i] != a[i-1]) b.push_back(a[i]);
    
    //for (int i : b) cout << i << ' ';
    //cout << endl;
    map<int, int> cnt;
    int m = (int)b.size();
    for (int i=0; i<m; i++) {
        cnt[b[i]]++;
    }
    cnt[b[0]]--;
    cnt[b.back()]--;
    int ans = m-1;
    for (auto p : cnt) ans = min(ans, p.second+1);
    cout << ans << '\n';
}

int main() {
    int t;
    for (cin >> t; t; t--)
        solve();
}