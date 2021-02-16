#include <bits/stdc++.h>
using namespace std;

long long A, B;
int n;
long long a[(int)(2e5)+10], b[(int)(2e5)+10];
long long d[(int)(2e5)+10];

void solve() {
    cin >> A >> B >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    long long totalDmg = 0;
    for (int i=0; i<n; i++) {
        d[i] = ((b[i] + A - 1) / A) * a[i];
        totalDmg += d[i];
    }
    
    int poss = (B >= totalDmg);
    for (int i=0; i<n; i++) {
        poss |= ((B > (totalDmg - d[i])) && (B - totalDmg > -a[i]));
    }

    cout << (poss ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}