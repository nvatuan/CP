#include <bits/stdc++.h>
using namespace std;

string s;
int x;

char a[200005];

void solve() {
    cin >> s; cin >> x;
    fill(a, a + s.length(), 'x');

    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (i - x >= 0) {
                if (a[i-x] == '1') { cout << "-1\n"; return; }
                if (a[i-x] == 'x') a[i-x] = '0';
            }
            if (i + x < n) {
                if (a[i+x] == '1') { cout << "-1\n"; return; }
                if (a[i+x] == 'x') a[i+x] = '0';
            }
        } else {
            if (i - x >= 0) {
                if (a[i-x] == '1') { continue; }
                if (a[i-x] == 'x') { a[i-x] = '1'; continue; }
            }
            if (i + x < n) {
                if (a[i+x] == '1') { continue; }
                if (a[i+x] == 'x') { a[i+x] = '1'; continue; }
            }
            cout << "-1\n"; return;
        }
    }
    for (int i = 0; i < s.length(); i++) cout << (a[i] == 'x' ? '1' : a[i]);
    cout << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}