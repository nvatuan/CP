#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
int grid[100][100];
int missing[100*100];

void solve() {
  cin >> n >> m;
  assert(n < 100);

  for (int x,i=0; i<m; i++) {
    cin >> x; missing[x] = 1;
  }

  ll matches = (ll)n*(n+1)/2*3;
  int level=0;
  {
  int r=1, c=0;
  for (int i=1; i<=matches; i++) {
    grid[r][c] = i;
    if (level % 2 == 0) r--, c++;
    else r -= 2, c += 2;

    if (r < 0) {
      level++;
      if (level % 2 == 1) r = level, c = 1;
      else {
        r = level+1;
        c = 0;
      }
    }
  }
  }

  level++; // last row zero
  // for (int i=0; i<level; i++) {
  //   for (int j=0; j<level; j++) {
  //     cout << grid[i][j] << ' ';
  //   }
  //   cout << endl;
  // }


  ll ans=0;
  // search |/ first
  for (int i=0; i<level; i+=2) {
    for (int j=0; j<level; j+=2) {
      if (i + j > n*2) continue;
      for (int e=2;; e+=2) {
        if (i+e >= level or j+e >= level) break;
        if (i+j+e > 2*n) break;
        int tri = 1;

        int r=i, c=j;
        for (int k=e; k; k--) {
          r++;
          if (missing[grid[r][c]]) tri=0;
        }
        for (int k=e; k; k--) {
          r--; c++;
          if (missing[grid[r][c]]) tri=0;
        }
        for (int k=e; k; k--) {
          c--;
          if (missing[grid[r][c]]) tri=0;
        }

        ans += tri;
        // if (tri) cerr << i << ' ' << j << endl;
      }
    }
  }
  // cerr << "--: " << ans << endl;

  // search |\ next
  for (int i=2; i<level; i+=2) {
    for (int j=2; j<level; j+=2) {
      if (i + j > n*2) continue;
      for (int e=2;; e+=2) {
        if (i-e < 0 or j-e < 0) break;
        int tri = 1;

        int r=i, c=j;
        for (int k=e; k; k--) {
          r--;
          if (missing[grid[r][c]]) tri=0;
        }
        for (int k=e; k; k--) {
          r++; c--;
          if (missing[grid[r][c]]) tri=0;
        }
        for (int k=e; k; k--) {
          c++;
          if (missing[grid[r][c]]) tri=0;
        }

        ans += tri;
      }
    }
  }

  // cerr << "level: " << level << '\n';
  cout << ans << '\n';
}

int main() {
  // int t;
  // cin >> t;
  // while (t--)
    solve();
}
