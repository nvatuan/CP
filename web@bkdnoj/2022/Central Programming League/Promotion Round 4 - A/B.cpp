#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

void solve() {
  cin >> n;
  vector<ll> v (n);
  ll xsum = 0;
  for (ll &i : v) {
    cin >> i;
    xsum ^= i;
  }
  v.push_back(xsum);
  n += 1;
  for (int i=0; i<n; i++) v.push_back(v[i]);
  n = v.size();

  vector<ll> pf (n+1, 0);
  for (int i=1; i<=n; i++) {
    pf[i] = pf[i-1] ^ v[i-1];
  }

  // --

  int Q; cin >> Q;
  for (ll l, r; Q; Q--) {
    cin >> l >> r;
    l -= 1, r -= 1;
    l %= n; r %= n;
    cout << (pf[r+1] ^ pf[l]) << '\n';
  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
