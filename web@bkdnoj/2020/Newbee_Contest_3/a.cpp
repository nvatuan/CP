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
int n, k;
long long S;

void solve() {
    S = 0;

    cin >> n >> k;
    multiset<long long> select;
    while (n--) {
        long long tmp;
        cin >> tmp;
        select.insert(tmp);
    }
    while (k--) {
        long long sel = *select.rbegin();
        //cerr << sel << endl;
        select.erase(prev(select.end()));
        S += sel;
        select.insert(sel/2);
    }
    cout << S << endl;
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}