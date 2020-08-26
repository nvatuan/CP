#include <bits/stdc++.h>
using namespace std;

const int __MULTITEST = 1;
const int __DEBUGMODE = 0;
#define db if(__DEBUGMODE)

template<typename T>
T In() { T x; cin >> x; return x; }

// -- solve
int n, m;
int a[200001], b[200001];
int asort[200001];
long long s[200002];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i] >> b[i];
    std::copy(a, a + m, asort);
    std::sort(asort, asort+m);
    
    s[m] = 0;
    for (int i = m-1; i >= 0; i--) s[i] = s[i+1] + asort[i];

    long long ans = -1;
    for (int i = 0; i < m; i++) {
        int u = std::upper_bound(asort, asort + m, b[i]) - asort;
        if (n < m - u) {
            u = m - n;
        }

        int cnt = m - u;

        long long subans = s[u];
        if (a[i] > b[i]) {
            subans -= a[i];
            cnt--;
        } 

        subans += a[i]; cnt++;
        subans += 1LL * b[i] * (n - cnt);
        ans = max(ans, subans);
    }

    cout << ans << '\n';
}

// --
int main() {
    for (int t = (__MULTITEST ? In<int>() : 1); t; t--) solve();
}