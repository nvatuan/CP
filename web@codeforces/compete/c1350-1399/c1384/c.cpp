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
    int n; cin >> n;
    string a, b; cin >> a >> b;
    //
    bool flag = true;
    for (int i = 0; i < n; i++) {
        flag &= (a[i] <= b[i]);
    }
    if (! flag) {
        cout << -1 << '\n';
        return;
    }
    //
    vector<set<char>> vsa (20);
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            vsa.insert(b[i]])
        }
    }

    cout << max(sa.size(), sb.size()) << endl;
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}