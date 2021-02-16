#include <bits/stdc++.h>
using namespace std;

bool explode(int val, vector<int> a) {
    int mana = val;
    for (int & i : a) {
        if (i < val) {
            mana -= (val - i);
            if (mana < 0) return true;
        }
    }
    return false;
}

void solve() {
    int n; cin >> n;
    vector<int> a (n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int L = 0, R = (int)(1e9 + 20);
    while ( L + 1 < R ) {
        int mid = L + (R - L) / 2;
        if (explode(mid, a)) R = mid;
        else L = mid;
    }
    cout << R << '\n';
}

int main() {
    int t; cin >> t;
    for (int tt=1; tt<=t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
}