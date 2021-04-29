#include <bits/stdc++.h>
using namespace std;

string s;
int n;

void solve() {
    cin >> s;
    n = (int)(s.length());

    int poss = 0;
    for (int par=0; par < n; par++) {
        int good=1;
        int rest=0;
        for (int i=0; i<par; i++) {
            if (s[i] == '1') {
                if (!rest) {
                    rest = 1;
                } else {
                    good = 0;
                    break;
                }
            } else {
                if (rest) rest = 0;
            }
        }
        for (int j=par; j<n; j++) {
            if (s[j] == '0') {
                if (!rest) {
                    rest = 1;
                } else {
                    good = 0;
                    break;
                }
            } else {
                if (rest) rest = 0;
            }
        }
        if (good) poss = 1;
    }

    int good=1, rest=0;
    for (int i=0; i<n; i++) {
        if (s[i] == '1') {
            if (!rest) {
                rest = 1;
            } else {
                good = 0;
            }
        } else {
            if (rest) rest = 0;
        }
    }
    if (good) poss = 1;
    cout << (poss ? "YES" : "NO") << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}