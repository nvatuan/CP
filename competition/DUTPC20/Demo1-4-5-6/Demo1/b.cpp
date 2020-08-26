#include <bits/stdc++.h> 
using namespace std;
 
#ifdef LOCAL
#include "debug.hpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

const int __MULTITEST = 0;

template<typename T>
T In() { T x; cin >> x; return x; }

// ================================================= SOLUTION =================================================
int n;
int a[101], b[101], c[101];

int MOD = int(1e9) + 7;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> a[i] >> b[i] >> c[i]; }
    
    map<pair<int, int>, int> parallel;
    for (int i = 0; i < n; i++) {
        int g = __gcd(a[i], b[i]);
        a[i] /= g;
        b[i] /= g;
        parallel[make_pair(a[i], b[i])]++;
    }

    long long ans = 0;
    for (auto it = parallel.begin(); it != parallel.end(); it++) {
        for (auto it2 = next(it); it2 != parallel.end(); it2++) {
            for (auto it3 = next(it2); it3 != parallel.end(); it3++) {
                ans += (it->second * it2->second % MOD * it3->second) % MOD;
                if (ans > MOD) ans -= MOD;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}