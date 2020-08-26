#include <bits/stdc++.h>
using namespace std;

int n;
char s[51][51];
string st;

void solve() {
    cin >> n;
    cin >> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s[i][j] = st[i + j];
        }
    }

    string ans (n, '1');
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < n; j++) {
            flag &= (s[i][j] == s[i][0]);
        }
        if (flag) {
            ans[i] = s[i][0];
        }
    }
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}