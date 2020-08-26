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
    long long k;
    int n;
    cin >> n >> k;
    vector<int> a (n);
    for (int& i : a) cin >> i;

    set<vector<int>> dup;
    while(k--) {
        debug(k);
        debug(a);
        if (dup.find(a) == dup.end()) {
            dup.insert(a);
            int Max = INT_MIN;
            for (const int& i : a) Max = max(Max, i);
            for (int i = 0; i < n; i++) {
                a[i] = Max - a[i];
            }
        } else {
            if (k % 2 == 1) {
                for (const int& i : a) cout << i << ' ';
                cout << '\n';
                return;
            }
            int Max = INT_MIN;
            for (const int& i : a) Max = max(Max, i);
            for (int i = 0; i < n; i++) {
                a[i] = Max - a[i];
            }
        }
    }
    for (const int& i : a) cout << i << ' ';
    cout << '\n';
    return;
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}