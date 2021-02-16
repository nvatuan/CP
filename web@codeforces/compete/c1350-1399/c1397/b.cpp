#include <bits/stdc++.h>
using namespace std;

int n;
long long a[1000000];

int LIM = (int) 1e9;
int cMax = 0;

long long binExp(long long b, long long e) {
    if (e == 0) return 1;
    if (e == 1) return b;
    if (e & 1) return binExp(b*b, e/2) * b;
    else return binExp(b*b, e/2);
}

long long cost(long long c) {
    long long res = 0;
    for (int i = 0; i < n; i++)
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);


    cout << ans << '\n';
}

int main() {
    // int t; cin >> t;
    // while(t--)
        solve();
}