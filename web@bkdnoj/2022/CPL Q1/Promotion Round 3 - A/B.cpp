#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
map< tuple<int, int, int>, int > lines;
map< tuple<int, int>, int > cnt;
int nonlinear=0;

ll a, b, c;

const ll M = int(1e9) + 7;

ll c2(ll x) {
  if (x < 2) return 0;
  return (x * (x-1)) / 2;
}

void solve() {
  cin >> n;
  ll ans = 0;
  ll dups = 0;
  for (int i=0; i<n; i++) {
    cin >> a >> b >> c;
    ll g=__gcd(a, b);
    if (g != 0) {
      a /= g;
      b /= g;
    }

    tuple<int, int, int> tup {a, b, c};
    // not allowing duplicates
    if (lines[tup]) continue;
    lines[tup] = 1;

    dups += cnt[{a, b}];
    cnt[{a, b}]++;

    ll np = (ll)lines.size() - cnt[{a, b}];
    ans += (c2(np) - dups + c2(cnt[{a, b}]) + M) % M;
    ans %= M;
    // cerr << i << ' ' << "@" << ans << '\n';
    // cerr << np << '\n';
  }
  cout << ans << '\n';
}

int main() {
  // int t;
  // cin >> t;
  // while (t--)
    solve();
}
