#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;

    for (int neg=0, pos=0; pos < n and neg < n; ) {
        if (a[pos] > 0) {
            if (neg < pos) neg = pos;
            if (a[neg] >= 0) neg++;
            else {
                int tmp = min(a[pos], abs(a[neg]));
                a[pos] -= tmp;
                a[neg] += tmp;
            }
        } else pos++;
    }
    //for (int i : a) cout << i << ' ';
    //cout << endl;
    long long ans = 0;
    for (int i : a)
        if (i > 0) ans += i;
    cout << ans << '\n';
    return;
}

int main() {
    int t; cin>>t;
    while(t--)
        solve();
}