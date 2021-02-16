#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int ans = 0;
    int n = s.length();
    int l = 0, r = 1;
    while (l < n and r < n) {
        if (s[l] != '(') l++;
        else
        if (s[r] != ')') {
            if (r < l) r = l+1;
            else r++;
        } else {
            if (r < l) r = l + 1;
            else {
                ans++;
                l++;
                r++;
            }
        }
    }
    l = 0, r = 1;
    while (l < n and r < n) {
        if (s[l] != '[') l++;
        else
        if (s[r] != ']') {
            if (r < l) r = l + 1;
            else r++;
        } else {
            if (r < l) r = l + 1;
            else {
                ans++;
                l++;
                r++;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}