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
    for (int& i : a) cin >> i;

    int Max = 0;
    for (int i : a) Max = max(Max, i);

    cout << (count(a.begin(), a.end(), Max) == n ? n : 1) << '\n';
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}