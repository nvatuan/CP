#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<pair<ll, ll>> A, B;

ll dist(vector<pair<ll,ll>> &arr, int i, int j) {
  return abs(arr[i].first - arr[j].first) * abs(arr[i].second - arr[j].second);
}
ll dst(pair<ll,ll> p1, pair<ll, ll> p2) {
  return abs(p1.first - p2.first) * abs(p1.second - p2.second);
}

vector<vector<ll>> memoir (1005, vector<ll>(1005, -1));

ll dp(int ai, int bi) {
  if (ai == 0 and bi == 0) return dst(A[0], B[0]);

  if (memoir[ai][bi] == -1) {
    ll val=0;
    if (ai == 0) val = dp(ai, bi-1) + dist(B, bi-1, bi);
    else {
      val = min(
        dp(ai-1, bi) + dist(A, ai-1, ai),
        dp(ai, bi-1) + dist(B, bi-1, bi)
      );
    }
    memoir[ai][bi] = val;
  }
  return memoir[ai][bi];
}

int main() {
  cin >> m >> n;
  for (int i=0; i<m; i++) {
    int x, y;
    cin >> x >> y;
    A.push_back({x, y});
  }
  for (int i=0; i<n; i++) {
    int x, y;
    cin >> x >> y;
    B.push_back({x, y});
  }

  cout << dp(m-1, n-1) << '\n';
}
