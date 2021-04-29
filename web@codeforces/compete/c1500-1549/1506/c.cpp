#include <bits/stdc++.h>
using namespace std;

string a, b;

void solve() {
    cin >> a >> b;


    int na = (int)(a.length());
    int nb = (int)(b.length());

    int ans = na + nb;

    // cerr << "NEWTEST\n";
    // cerr << "@a=" << a << "]\n";
    // cerr << "@b=" << b << "]\n";
    // cerr << "\n";
    for (int i1=0; i1<na; i1++) {
        string a_substr = "";
        for (int i2=i1; i2<na; i2++) {
            a_substr += a[i2];

            for (int j1=0; j1<nb; j1++) {
                string b_substr = "";
                for (int j2=j1; j2<nb; j2++) {
                    b_substr += b[j2];

                    if (j2-j1 > i2-i1) break;
                    if (b_substr == a_substr) {
                        ans = min(ans, na - (i2-i1+1) + nb - (j2-j1+1));
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}