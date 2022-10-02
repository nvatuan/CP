#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int r, c;
int n, m;

void solve() {
  cin >> n;
  cin >> r >> c;
  vector<vector<int>> v (n, vector<int> (n, 0));
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      cin >> v[i][j];

  r--, c--;

  int mx = v[r][c];
  int nr, nc;
  int ans = 0;
  while (true) {
    int found = 0;
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++) {
        if ( (abs(i-r) == 1 and abs(j-c) > 1) or (abs(i-r) > 1 and abs(j-c) == 1) ) {
          if (v[r][c] < v[i][j]) {
            if (v[i][j] < mx) {
              nr = i;
              nc = j;
              mx = v[i][j];
              found = 1;
            }
          }
        }
      }

    if (found==0) break;
    r = nr;
    c = nc;
    ans++;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // int t;
  // cin >> t;
  // while (t--)
    solve();
}
