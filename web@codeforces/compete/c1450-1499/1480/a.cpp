#include <bits/stdc++.h>
using namespace std;

void solve() {
    int turn = 1;
    string s;
    cin >> s;

    int n = (int)(s.length());
    for (int i=0; i<n; i++) {
        if (turn) {
            if (s[i] == 'a') {
                s[i] = 'b';
            } else {
                s[i] = 'a';
            }
        } else {
            if (s[i] == 'z') {
                s[i] = 'y';
            } else {
                s[i] = 'z';
            }
        }
        turn^=1;
    }
    cout << s << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}