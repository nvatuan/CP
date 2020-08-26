#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.hpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

typedef pair<long long, int> Pair;

int N, M;
int C[1000002];

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> C[i];
    debug(N, M);
    debug(vector<int> (C, C + N));

    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    for (int i = 1; i < min(M + 1, N); i++)
        pq.push(make_pair(C[i], i));
    int furthest = min(M + 1, N);

    long long ans = LLONG_MAX;
    while (not pq.empty()) {
        Pair p = pq.top();
        pq.pop();

        if (p.second == N-1) ans = min(ans, p.first - C[N-1]);
        if (C[p.second] == 0) continue;

        for (int i = max(p.second + 1, furthest); i < min(p.second + M + 1, N); i++) {
            pq.push(make_pair(p.first + C[i], i));
        }
        furthest = max(furthest, min(p.second + M + 1, N));
    }
    printf("%lld\n", (ans == LLONG_MAX ? -1 : ans));
}

int main() {
    int t; cin >> t;
    for (int it = 1; it <= t; it++) {
        printf("Case #%d: ", it);
        solve();
    }
}