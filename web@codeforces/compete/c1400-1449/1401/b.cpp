#include <bits/stdc++.h>
using namespace std;

int a[3];
int b[3];

void solve() {
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];

    int ans = 0;
    int elim1 = min(a[1], b[0] + b[1]);
    if (elim1 < a[1]) { // a[1] exist, b[0..1] does not
        a[1] -= elim1;
        b[0] = b[1] = 0;

        int incMin = min(a[2], b[1]);
        ans += (incMin * 2);
        a[2] -= incMin;
        b[1] -= incMin;

        int decMin = min(a[1], b[2]);
        ans += (decMin * (-2));
    } else { // a[1] == 0, b[0..1] != 1
        a[1] = 0;

        int tmp = min(elim1, b[0]);
        elim1 -= tmp;
        b[0] -= tmp;
        tmp = min(elim1, b[1]);
        elim1 -= tmp;
        b[1] -= tmp;
        assert(elim1 == 0);

        int incMin = min(a[2], b[1]);
        ans = (incMin * 2);
    }

    cout << ans << '\n';    
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}