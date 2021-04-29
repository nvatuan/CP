#include <bits/stdc++.h>
using namespace std;

/*
    499973*499979
*/

typedef long long llong;
llong n, m, k;

void solve() {
    scanf("%lld%lld%lld", &n, &m, &k);
    vector<llong> a(n), b(m);
    for (int i=0; i<n; i++) scanf("%lld", &a[i]);
    for (int i=0; i<m; i++) scanf("%lld", &b[i]);
    if (n < m) {
        swap(n, m);
        swap(a, b);
    }

    llong same_til_lcm;
    llong G = __gcd(n, m);
    llong lcm = n*m/G;
    
    if (G == 1) {
        same_til_lcm = 0;
        unordered_map<int, int> cnt;

        for (int c : a) cnt[c]++;
        for (int c : b) {
            same_til_lcm += cnt[c];
        }
    } else {
        same_til_lcm = 0;
        map<int, map<int, int>> cnt_modulo_g;

        for (int i=0; i<n; i++) {
            cnt_modulo_g[i%G][a[i]]++;
        }

        for (int i=0; i<m; i++) {
            same_til_lcm += cnt_modulo_g[i%G][b[i]];
        }
    }
    printf("LCM=%lld\nsame=%lld\n", lcm, same_til_lcm);
    llong diff_til_lcm = lcm - same_til_lcm;

    llong lcm_repeat = k / diff_til_lcm;
    k %= diff_til_lcm;
}

int main() {
    solve();
}