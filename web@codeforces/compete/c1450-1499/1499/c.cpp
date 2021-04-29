#include <bits/stdc++.h>
using namespace std;

int n;
long long c[(int)(2e5)+10];

void try_walk(int flip, long long &ans) {
    long long cost[2];
    cost[0] = cost[1] = (long long)(2e16);

    long long sum[2]={};
    sum[0] = sum[1] = 0LL;

    long long mn[2];
    mn[0] = mn[1] = (long long)(2e9);

    int trav_x = 0, trav_y = 0;

    for (int i=0; i<n; i++) {
        if (i&1) {
            sum[0] += c[i];
            mn[0] = min(mn[0], c[i]);
            cost[0] = ((n-trav_x) * mn[0] + sum[0] - mn[0]);
            trav_x++;
        } else {
            sum[1] += c[i];
            mn[1] = min(mn[1], c[i]);
            cost[1] = ((n-trav_y) * mn[1] + sum[1] - mn[1]);
            trav_y++;
        }
        // fprintf(stderr, "i=%d cost1=%lld cost2=%lld\n", i, cost[0], cost[1]);
        ans = min(ans, cost[0] + cost[1]);
    }
}

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) scanf("%lld", &c[i]);

    long long ans = LLONG_MAX;
    try_walk(0, ans);
    // try_walk(1, ans);
    printf("%lld\n", ans);
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}