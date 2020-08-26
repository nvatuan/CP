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
bool ran = false;

int MOD = int(1e9) + 9;

const int SIZE = 10000001;
long long ans[SIZE];

int n;

void solve() {
    if (not ran) {
        ans[1] = 1;
        long long start = 1;
        
        for (int i = 3; i < SIZE; i += 2) {
            ans[i] = 4*start % MOD + 10*(i - 1);
            ans[i] += ans[i-2];
            while (ans[i] >= MOD) ans[i] -= MOD;
            
            start = 1LL*i*i;
        }

        ans[2] = 10;
        start = 3;
        for (int i = 4; i < SIZE; i += 2) {
            ans[i] = ans[i-2];
            ans[i] += 1LL * (i - 2) * (i - 2) % MOD * 4 + start * 10;
            while (ans[i] >= MOD) ans[i] -= MOD;
            start += 2;
        }

        ran = true;
    }
    cin >> n;
    cout << ans[n] << '\n';
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}