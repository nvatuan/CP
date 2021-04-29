#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int poss = 1;

    int at = 0;
    int t = count(s.begin(), s.end(), 'T');

    int am = 0;
    int m = count(s.begin(), s.end(), 'M');

    if (t != m*2) poss = 0;

    for (int i=0; i<n; i++) {
        if (s[i] == 'M') {
            am++;
            m--;
            if (at < am || m > t) poss = 0;
        } else {
            at++;
            t--;
        }
    }

    cout << (poss ? "YES" : "NO") << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}