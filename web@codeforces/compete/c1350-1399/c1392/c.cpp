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
void solve() {
    int n;
    cin >> n;
    vector<int> a (n);
    for (int & i : a) cin >> i;

    long long ans = 0;
    for (int i = 1; i < n; i++)
        if (a[i-1] > a[i]) ans += (a[i-1] - a[i]);
    
    cout << ans << '\n';
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}