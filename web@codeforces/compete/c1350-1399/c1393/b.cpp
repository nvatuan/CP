#include <bits/stdc++.h>
using namespace std;

int n;

int q;
char c;
int x;

int fourSide = 0;
int twoSide = 0;

int s[100001];

void add(int x) {
    s[x]++;
    if (s[x] % 4 == 0) {
        twoSide--;
        fourSide++;
    } else 
    if (s[x] % 2 == 0) {
        twoSide++;
    }
}

void remove(int x) {
    if (s[x] % 4 == 0) {
        twoSide++;
        fourSide--;
    } else 
    if (s[x] % 2 == 0) {
        twoSide--;
    }
    s[x]--;
}

void solve() {
    for (cin >> n; n; n--) { cin >> x; add(x); }
    for (cin >> q; q; q--) {
        cin >> c >> x;
        if (c == '+') add(x);
        else remove(x);
        if (
            (fourSide == 1 && twoSide >= 2)
            or
            (fourSide >= 2)
        ) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0);

    // int t; cin >> t;
    // while(t--) solve();
    solve();
}