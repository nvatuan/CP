#include <bits/stdc++.h>
using namespace std;

int n, m;
typedef long long ll;

ll a[(int)(3e5)], b[(int)(3e5)];

void solve() {
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<m; i++) cin >> b[i];

    if (n==1) {
        for (int i=0; i<m; i++) cout << a[0] + b[i] << ' ';
        cout << endl;
        return;
    }

    sort(a, a+n);
    ll d = 0;
    for (int i=1; i<n; i++) d = __gcd(d, a[i]-a[i-1]);

    // fprintf(stderr, "d = %d\n", d);
    if (d == 0) {
        for (int i=0; i<m; i++) {
            cout << a[0] + b[i] << ' ';
        }
        cout << endl;
        return;
    }

    ll md = a[0] % d;
    for (int i=0; i<n; i++) {
        if (a[i] % d != md) {
            md = -1;
            break;
        }
    }

    // fprintf(stderr, "md = %d\n", md);
    
    if (d == 1 or md == -1) {
        for (int i=0; i<m; i++) cout << 1 << ' ';
        cout << endl;
    } else {
        for (int i=0; i<m; i++) {
            ll new_md = md + b[i];
            ll g = __gcd(new_md, d);
            cout << g << ' ';
        }
        cout << endl;
    }
}

int main() {
    solve();
}