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
    string s;
    cin >> s;
    
    s += 'x';

    vector<int> segs;
    int ones = 0;
    for (int i = 0; i < (int) s.length(); i++) {
        if (s[i] == '1') ones++;
        else {
            segs.push_back(ones);
            ones = 0;
        }
    }

    sort(segs.begin(), segs.end(), greater<int>());

    long long ans = 0;
    for (int i = 0; i < (int) segs.size(); i++) {
        if (i & 1);
        else ans += segs[i];
    }
    cout << ans << endl;
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}