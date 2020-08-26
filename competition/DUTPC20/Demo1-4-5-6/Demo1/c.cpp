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
int k, n;
long long ans;

long long choose_2(int n) {
    return 1LL * (n) * (n-1) / 2;
}

void solve() {
    cin >> n >> k;
    ans = 0;
    
    // choose 2 from modulo k = 0
    ans = choose_2(n/k); 

    for (int m1 = 1, m2 = k-1; m1 < m2; m1++, m2--) {
        int c1 = n/k + (n%k >= m1);
        int c2 = n/k + (n%k >= m2);
        debug(m1, c1, m2, c2);
        ans += (1LL * c1 * c2);
    }

    // one more case: m1 == m2 == k/2
    if (k % 2 == 0) {
        int c = n/k + (n%k >= (k/2));
        ans += (choose_2(c));
    }
    cout << ans << '\n';
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}