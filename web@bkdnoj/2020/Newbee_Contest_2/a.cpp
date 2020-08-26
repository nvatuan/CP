#include <bits/stdc++.h> 
using namespace std;
 
#ifdef LOCAL
#include "debug.hpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

const int __MULTITEST = 1;

template<typename T>
T In() { T x; cin >> x; return x; }

// ================================================= SOLUTION =================================================
int n, s;
int MOD = int(1e9) + 7;

void add_mod(long long& a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void solve() {
    cin >> n >> s;
    vector<vector<long long>> dp (n + 5, vector<long long> (s + 5, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int b = 0; b <= min(s - 1, i); b++) {
            add_mod(dp[i+1][0], dp[i][b]);
            add_mod(dp[i+1][b+1], dp[i][b]);
        }
    }

    debug(dp);

    long long ans = 0;
    for (int b = 0; b < min(s, n); b++) {
        add_mod(ans, dp[n-1][b]);
    }
    cout << ans << '\n';
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}