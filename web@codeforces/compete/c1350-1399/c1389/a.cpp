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
    int l, r;
    cin >> l >> r;
    if (l * 2 > r) {
        cout << "-1 -1\n";
    } else {
        cout << l << " " << l*2 << "\n";
    }
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}