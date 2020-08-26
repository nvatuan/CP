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
    int n, k, l;
    cin >> n >> k >> l;

    vector<int> d (n, 0);
    for (int& i : d) cin >> i;
    //
    vector<int> p;
    for (int i = 0; i < k; i++) p.push_back(i);
    for (int i = k; i > 0; i--) p.push_back(i);
    assert(p.size() == 2*k);

    auto possible = [&](int ptr, int t) -> bool {
        while (ptr < n) {
            if (d[ptr] + p[t % (2*k)] > l) return false;
            t++;
            ptr++;
        }
        return true;
    };

    //
    int t = 0;
    int ptr = 0;
    while (ptr < n) {
        if (d[ptr] + p[t % (2*k)] > l) {
            cout << "No\n";
            return;
        }
        if (possible())
        t++
    }
    cout << "Yes\n";
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}