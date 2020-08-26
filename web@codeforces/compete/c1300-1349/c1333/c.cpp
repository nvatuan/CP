#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
}

vector<int> a (200005);
vector<int> goodArrayEndWith (200005, 0);
unordered_map<llong, int> prefixIndex;

void solve() {
    int n;
    scanf("%d", &n);
    n++;
    for (int i = 1; i < n; i++) scanf("%d", &a[i]);
    //
    llong prefix = 0;
    int recentZero = 0;
    prefixIndex[0] = 0;
    //
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            recentZero = i;
            goodArrayEndWith[i] = i+1;
        } else {
            prefix += a[i];
            if (prefixIndex.find(prefix) == prefixIndex.end()) {
                prefixIndex[prefix] = i;
                goodArrayEndWith[i] = recentZero + 1;
                if (goodArrayEndWith[i] < goodArrayEndWith[i-1]) goodArrayEndWith[i] = goodArrayEndWith[i-1];
            } else {
                goodArrayEndWith[i] = prefixIndex[prefix] + 2;
                if (goodArrayEndWith[i] <= recentZero) goodArrayEndWith[i] = recentZero + 1;
                if (goodArrayEndWith[i] < goodArrayEndWith[i-1]) goodArrayEndWith[i] = goodArrayEndWith[i-1];
                prefixIndex[prefix] = i;
            }
        }
    }
    //
    llong ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != 0) ans += (i - goodArrayEndWith[i] + 1);
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
}