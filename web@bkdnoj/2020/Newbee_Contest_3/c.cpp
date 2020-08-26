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
int L;
int up[1000002], down[1000002];

void solve() {
    scanf("%d", &L);
    int ans = L;

    for (int i = 1; i < L; i++) {
        scanf("%d", &up[i]);
    }
    for (int i = 1; i < L; i++) {
        scanf("%d", &down[i]);
    }
    for (int i = 1; i < L; i++) {
        int u = up[i];
        int d = down[i];
        ans = max({ans, i+u, i+d});
        //cout << i << ' ' << u << ' ' << d << endl;
    }

    cout << ans << endl;
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}