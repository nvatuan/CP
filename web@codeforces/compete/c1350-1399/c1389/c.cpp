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
string s;

int countPair(string pair) {
    int i = 0;
    int pos = 0;
    int occ = 0;

    while (pos < s.length()) {
        size_t pos2 = s.find(pair[i], pos);
        if (pos2 == string::npos) return occ;
        else {
            if (i) occ += 1;
            i ^= 1;
            pos = pos2 + 1;
        }
    }
    return occ;
}

void solve() {
    cin >> s;
    s = s.substr(1) + s[0];

    int ans = s.length() - 2;
    for (char c = '0'; c <= '9'; c++) {
        ans = min(ans, (int) s.length() - count(s.begin(), s.end(), c));
    }

    for (char c1 = '0'; c1 <= '9'; c1++) {
        for (char c2 = '0'; c2 <= '9'; c2++) {
            string p = "";
            p += c1; p += c2;
            ans = min(ans, (int) s.length() - countPair(p)*2);
            //cout << p << " " << countPair(p) << endl;
        }
    }
    cout << ans << '\n';

}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}