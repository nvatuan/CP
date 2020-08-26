#include <bits/stdc++.h>
using namespace std;

const int __MULTITEST = 1;

template<typename T>
T In() { T x; cin >> x; return x; }
// --
void solve() {
    long long n, r;
    cin >> n >> r;

    long long x = min(n - 1, r);

    long long result = x * (x+1)/2;
    if (r >= n) result += 1;
    cout << result << endl;
}

int main() {
    for (int t = (__MULTITEST ? In<int>() : 1); t; t--) solve();
}