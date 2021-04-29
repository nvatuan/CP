#include <bits/stdc++.h>
using namespace std;

string s;

int valid (string x) {
    int open = 0;
    for (char c : x) {
        if (c == '(') open++;
        else open--;
        if (open < 0) return false;
    }
    if (open == 0) return true;
    return false;
}

void solve() {
    cin >> s;

    int n = (int)(s.length());
    for (int ia=0; ia<2; ia++) {
        for (int ib=0; ib<2; ib++) {
            for (int ic=0; ic<2; ic++) {
                string t;
                for (int i=0; i<n; i++) {
                    switch (s[i]) {
                        case 'A':
                            if (ia) t += '(';
                            else t += ')';
                            break;
                        case 'B':
                            if (ib) t += '(';
                            else t += ')';
                            break;
                        case 'C':
                            if (ic) t += '(';
                            else t += ')';
                            break;
                        default:
                            break;
                    }
                }
                if (valid(t)) {
                    printf("YES\n");
                    return;
                }
            }
        }
    }
    printf("NO\n");
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}