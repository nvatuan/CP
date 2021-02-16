#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int m, n;
int h1, s1, h2, s2;
vector<vector<int>> G;
map<pair<int, int>, ll> cost;

vector<ll> dp[4];
const ll INF = (ll) 1e15;

void runDijsktra(int s, vector<ll> &dp) {
    dp.resize(n);
    fill(dp.begin(), dp.end(), INF);
    //
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push ({0LL, s});

    while (!pq.empty()) {
        ll curcost = pq.top().first;
        int curnode = pq.top().second;
        pq.pop();
        
        if (dp[curnode] < curcost) continue;
        dp[curnode] = curcost;

        for (auto nxt : G[curnode]) {
            ll tmp = cost[{curnode, nxt}];
            if (dp[nxt] > dp[curnode] + tmp) { 
                dp[nxt] = dp[curnode] + tmp;
                pq.push({dp[nxt], nxt});
            }
        }
    }
}

int onH1S1(int u) {
    return dp[0][u] + dp[1][u] == dp[0][s1];
}
int onH2S2(int u) {
    return dp[2][u] + dp[3][u] == dp[2][s2];
}

void solve() {
    runDijsktra(h1, dp[0]); runDijsktra(s1, dp[1]);
    runDijsktra(h2, dp[2]); runDijsktra(s2, dp[3]);
    // fprintf(stderr, "h1=%d, s1=%d, h2=%d, s2=%d\n", h1, s1, h2, s2);

    ll ans = 0;
    // meet at a node
    for (int i=0; i<n; i++) {
        if (i != s1 && i != s2) {
            if (onH1S1(i) and onH2S2(i))
                if (dp[0][i] == dp[2][i]) ans++;
        }
    }

    // meet at either of the school
    if (
        (onH1S1(s2) and dp[2][s2] <= dp[0][s2])
            or
        (onH2S2(s1) and dp[0][s1] <= dp[2][s1])
    ) ans++;

    // -- meet on the same edge
    // walk the opposite direction
    for (auto p : cost) {
        int u = p.first.first, v = p.first.second;
        ll c = p.second;
        //fprintf(stderr, "u=%d, v=%d, c=%lld\n", u, v, c);
        //fprintf(stderr, "dp[0][u]=%lld\n", dp[0][u]);
        //fprintf(stderr, "dp[2][u]=%lld\n", dp[2][u]);
        //fprintf(stderr, "dp[0][v]=%lld\n", dp[0][v]);
        //fprintf(stderr, "dp[2][v]=%lld\n", dp[2][v]);
        
        if (
            onH1S1(u) and onH1S1(v) and onH2S2(u) and onH2S2(v)
                and
            (dp[0][u] < dp[0][v] and dp[2][u] > dp[2][v])
                and
            (abs(dp[0][u] - dp[2][v]) < c)
        ) ans++;
    }

    // walk the same direction - Infinity
    for (auto p : cost) {
        int u = p.first.first, v = p.first.second;
        ll c = p.second;
        if (
            onH1S1(u) and onH1S1(v) and onH2S2(u) and onH2S2(v)
                and
            dp[0][u] == dp[2][u]
        ) ans = INF*2;
    }

    // --
    cout << (ans > INF ? -1LL : ans) << '\n';
}

int main() {
    while (1) {
        cin >> n >> m;
        if (!n && !m) break;
        cin >> h1 >> s1 >> h2 >> s2;
        h1--, s1--, h2--, s2--;
        G.resize(n);
        fill(G.begin(), G.end(), vector<int>());
        cost.clear();
        for (int i=0; i<m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
            cost[{a, b}] = cost[{b, a}] = c;
        }

        solve();
    }
}