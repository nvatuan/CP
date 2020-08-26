#include <bits/stdc++.h>
using namespace std;

int dif[40005];

int a, b, q;
long long query(long long x) {
    int prod = a*b;
    return x/prod*dif[prod] + dif[x%prod];
}

void solve() {
    cin >> a >> b >> q;

    for (int i = 1; i <= a*b; i++) {
        int v1 = i%a%b;
        int v2 = i%b%a;
        dif[i] = dif[i-1] + (v1 != v2);
    }

    long long l, r;
    while (q--) {
        cin >> l >> r;
        cout << query(r) - query(l-1) << ' ';
    }
    cout << '\n';
}


int main() {
    int t; cin >> t;
    while(t--)
        solve();
}
