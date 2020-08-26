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
int n, k, z;
int a[100001];

int addr[100002];
int *partial = addr + 1;

void solve() {
    cin >> n >> k >> z;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    fill(partial, partial + 2*n, 0);

    partial[-1] = 0;
    for (int i = 0; i < n; i++) partial[i] = partial[i-1] + a[i];
    partial[n] = partial[n-1] + a[n-2];

    int ans = 0;
    int prefix = a[0];
    for (int i = 1; i < k; i++) {
        int lap = min((k-i)/2, z);
        int kleft = k - i - lap*2;
        debug(i + kleft);
        debug(i);
        debug(lap);
        debug(ans);
        debug(kleft);

        prefix += a[i];

        ans = max(
            ans,
            prefix + (a[i-1] + a[i])*lap + (partial[i + kleft] - partial[i])
        );
        
        if (i + kleft - 1 >= i and i + kleft - 2 >= 0 and z > lap) {
            ans = max(
                ans,
                prefix + (a[i-1] + a[i])*lap + (partial[i + kleft - 1] - partial[i]) + a[i + kleft - 2]
            );
            debug(prefix);
            debug(a[i + kleft - 2]);
            debug(partial[i + kleft - 1] - partial[i]);
            debug(prefix + (a[i-1] + a[i])*lap + (partial[i + kleft - 1] - partial[i]) + a[i + kleft - 2]);
        }
        
    }
    ans = max(ans, partial[k]);

    cout << ans << endl;
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}