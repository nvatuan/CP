#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);

    if (a[0] == 0) {
        cout << a[1] / 3 + a[2] / 3<< endl;
        return 0;
    }

    ll ans = 0;

    ans += (a[0] / 3);
    ans += (a[1] / 3);
    ans += (a[2] / 3);
    a[0] %= 3;
    a[1] %= 3;
    a[2] %= 3;

    ll mn = min({a[0], a[1], a[2]});
    ans += mn;
    for (ll &i : a) {
        i -= mn;
    }

    sort(a, a+3);
    if (a[1] == a[2] && a[2] == 2) ans++;

    cout << ans << endl;
}