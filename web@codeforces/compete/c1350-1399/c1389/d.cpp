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
    vector<int> v (5);
    generate(v.begin(), v.end(), rand);
    debug(v);
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}