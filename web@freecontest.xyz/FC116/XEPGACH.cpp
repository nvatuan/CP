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
long long INF = (long long) 1e16;

void solve() {
    int n;
    cin >> n;

    vector<int> a (n), b (n);
    for (int i = 0; i < n; i++) { cin >> a[i] >> b[i]; }

    vector<int> ind (n);
    for (int i = 0; i < n; i++) ind[i] = i;
    
    long long ans = INF;
    do {
        long long subans = 0;
        for (int i = 0; i < n; i++) {
            subans += (a[ind[i]] * (i) + b[ind[i]] * (n - i - 1));
        }
        ans = min(subans, ans);
    } while (next_permutation(ind.begin(), ind.end()));

    cout << ans << '\n';
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}