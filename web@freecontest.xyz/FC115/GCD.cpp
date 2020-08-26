#include <bits/stdc++.h>
using namespace std;

const int __debug_mode = 1;
const int __multitest = 0;
#define db if(__debug_mode)

template<typename T>
T In() { T x; cin >> x; return x; }

// -- template ends here
void solve() {
    int n; cin >> n;
    multiset<int> s;
    for (int t, v, i = 0; i < n; i++) {
        cin >> t >> v;
        if (t == 1) {
            s.insert(v);
        } else {
            s.erase(v);
        }
        // --
        int g = 0;
        for (int i : s) g = __gcd(g, i);
        cout << g << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    for (int t = (__multitest ? In<int>() : 1); t; t--) solve();
}

