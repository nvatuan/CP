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

  int level=0;
  int r=1, c=0;
  for (int i=1; i<=n; i++) {
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

  for (int i=0; i<=n; i++) {
    for (int j=0; j<=n; j++) {
      cout << grid[i][j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  // int t;
  // cin >> t;
  // while (t--)
    solve();
}
