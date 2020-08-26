#include <bits/stdc++.h>
using namespace std;

const int __debug_mode = 1;
const int __multitest = 1;
#define db if(__debug_mode)

template<typename T>
T In() { T x; cin >> x; return x; }

// -- template ends here
void solve() {
    int n, k;
    cin >> n >> k;
    long long sum = 0;
    for (int v, i = 0; i < n; i++) {
        cin >> v;
        sum += v;
    }
    cout << (sum % k ? "NO\n" : "YES\n");
}

int main() {
    for (int t = (__multitest ? In<int>() : 1); t; t--) solve();
}

