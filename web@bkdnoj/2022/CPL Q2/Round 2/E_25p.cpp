#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct LCA {
    vector<ll> height, euler, first, segtree;
    vector<bool> visited;
    ll n;

    LCA(vector<vector<ll>> &adj, ll root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        ll m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<ll>> &adj, ll node, ll h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(ll node, ll b, ll e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            ll mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            ll l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    ll query(ll node, ll b, ll e, ll L, ll R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        ll mid = (b + e) >> 1;

        ll left = query(node << 1, b, mid, L, R);
        ll right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    ll lca(ll u, ll v) {
        ll left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

ll N, M;
string st;

vector<vector<ll>> adj;
vector<ll> rsum, dist;

void calrsum(ll r=0, ll p=-1) {
  if (p != -1) {
    dist[r] = dist[p]+1;
    rsum[r] += rsum[p];
  }
  for (auto to : adj[r]) {
    if (to == p) continue;
    calrsum(to, r);
  }
}

int main() {
  cin >> N >> M >> st;

  adj.resize(N);
  for (ll i=1; i<N; i++) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  rsum.resize(N);
  dist.resize(N, 1);
  for (ll i=0; i<N; i++) {
    rsum[i] = (st[i] == 'H');
  }
  calrsum(0);

  // cerr << "rsum: ";
  // for (ll i=0; i<N; i++) cerr << rsum[i] << ' ';
  // cerr << endl;

  // cerr << "dist: ";
  // for (ll i=0; i<N; i++) cerr << dist[i] << ' ';
  // cerr << endl;

  LCA lcax (adj);

  for (ll i=0; i<M; i++) {
    ll a, b; char c;
    cin >> a >> b >> c;
    a--; b--;

    if (a == b) {
      if (st[a] == c) cout << 1;
      else cout << 0;
      continue;
    }

    ll lca = lcax.lca(a, b);
    ll sum=0, dsum=0;
    // cerr << "@" << a <<  ' ' << b << ' ' << c << endl;
    // cerr << "lca=" << lca << endl;
    if (lca == 0) {
      sum = rsum[a] + rsum[b] - rsum[0];
      dsum = dist[a] + dist[b] - 1;
    } else {
      sum = rsum[a] + rsum[b] - rsum[lca] * 2 + (st[lca] == 'H');
      dsum = dist[a] + dist[b] - dist[lca] * 2 + 1;
    }
    // cerr << dsum << ' ' << sum << endl;
    if (
      (dsum != sum) or
      (c == 'H' && sum == dsum) or (c == 'G' && sum == 0)
    ) {
      cout << 1;
    } else cout << 0;
  }
  cout << '\n';
}
