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
const int SIZE = (int) 1e5 + 5;
int n;
int a[SIZE], dp[SIZE];
int prefix[SIZE];

void solve() {
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        a[i] = (int)(c - '0');
    }

    prefix[0] = 0;
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + a[i];

    map<int, int> cnt;
    for (int i = 1; i <= n; i++) cnt[prefix[i] - i]++;

    long long ans = 0;
    for (pair<int, int> p : cnt) {
        long long c = p.second;
        ans += (c * (c-1))/2;
    }
    ans += cnt[0];
    cout << ans << endl;
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}