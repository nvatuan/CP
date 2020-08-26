#include <bits/stdc++.h>
using namespace std;

const int SIZE = int(2e5) * 10;

string a, b;

int equi(int l1, int l2, int len) {
    bool flag = true;
    for (int rep = 0; rep < len; rep++)
        if (a[l1 + rep] != b[l2 + rep]) flag = false;
    if (flag) return true;

    if (len % 2 == 1) return false;

    if (equi(l1, l2 + len/2, len/2) and equi(l1 + len/2, l2, len/2)) return true;
    if (equi(l1, l2, len/2) and equi(l1 + len/2, l2 + len/2, len/2)) return true;
    return false;
}

void solve() {
    cin >> a >> b;
    assert(a.length() == b.length());
    cout << (equi(0, 0, a.length()) ? "YES\n" : "NO\n");
}

int main() {
//    int t; cin >> t;
//    while(t--)
        solve();
}
