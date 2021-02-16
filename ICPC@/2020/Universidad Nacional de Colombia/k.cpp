#include <bits/stdc++.h>
using namespace std;

string a, b;

void solve() {
    cin >> a >> b;
    int i1 = 0, i2 = 0;
    while (isalpha(a[i1])) i1++;
    while (isalpha(b[i2])) i2++;
    string p1 = a.substr(0, i1);
    string p2 = b.substr(0, i2);
    if (p1 != p2) {
        cout << (p1 > p2 ? '>' : '<') << endl;
    } else {
        string int1 = a.substr(i1), int2 = b.substr(i2);
        if (int1.length() != int2.length()) {
            cout << (int1.length() > int2.length() ? '>' : '<') << endl;
        } else {
            if (int1 == int2) cout << '=' << endl;
            else cout << (int1 > int2 ? '>' : '<') << endl;
        }
    }
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
}