#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
int grid[100][100];
int missing[100*100];
int level=0;

void gen() {
  ll matches = (ll)n*(n+1)/2*3;
  level=0;
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
}

map<int, int> most;

int exist(int sc=0) {
  if (!sc) most.clear();
  int yes=0;
  for (int i=0; i<level; i+=2) {
    for (int j=0; j<level; j+=2) {
      if (i + j > n*2) continue;
      for (int e=2;; e+=2) {
        if (i+e >= level or j+e >= level) break;
        if (i+j+e > 2*n) break;
        int tri = 1;

        vector<int> num;

        int r=i, c=j;
        for (int k=e; k; k--) {
          r++;
          if (missing[grid[r][c]]) tri=0;
          else {
            if (grid[r][c] > 0)
            if (!sc) num.push_back(grid[r][c]);
          }
        }
        for (int k=e; k; k--) {
          r--; c++;
          if (missing[grid[r][c]]) tri=0;
          else {
            if (grid[r][c] > 0)
            if (!sc) num.push_back(grid[r][c]);
          }
        }
        for (int k=e; k; k--) {
          c--;
          if (missing[grid[r][c]]) tri=0;
          else {
            if (grid[r][c] > 0)
            if (!sc) num.push_back(grid[r][c]);
          }
        }

        if (sc) {if (tri) return 1;}
        else if (tri) {
          yes = 1;
          for (int &n : num) {
            most[n]++;
          }
        }
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

        vector<int> num;

        int r=i, c=j;
        for (int k=e; k; k--) {
          r--;
          if (missing[grid[r][c]]) tri=0;
          else {
            if (grid[r][c] > 0)
            if (!sc) num.push_back(grid[r][c]);
          }
        }
        for (int k=e; k; k--) {
          r++; c--;
          if (missing[grid[r][c]]) tri=0;
          else {
            if (grid[r][c] > 0)
            if (!sc) num.push_back(grid[r][c]);
          }
        }
        for (int k=e; k; k--) {
          c++;
          if (missing[grid[r][c]]) tri=0;
          else {
            if (grid[r][c] > 0)
            if (!sc) num.push_back(grid[r][c]);
          }
        }

        if (sc) {if (tri) return 1;}
        else if (tri) {
          yes = 1;
          for (int &n : num) {
            most[n]++;
          }
        }
      }
    }
  }
  return yes;
}

int main() {
  cin >> n >> m;
  assert(n < 100);

  for (int x,i=0; i<m; i++) {
    cin >> x; missing[x] = 1;
  }
  gen();
  if (! exist(0)) {
    cout << "0\n\n";
    return 0;
  }

  vector<int> left;
  for (int i=1; i<=3*n*(n+1)/2; i++) {
    if (missing[i]) continue;
    left.push_back(i);
  }
  sort(left.begin(), left.end(), [&](int a, int b){
    return most[a] > most[b];
  });

  for (int i=0; i<left.size(); i++) {
    missing[left[i]] = 1;
    if (exist(1));
    else {
      cout << i+1 << '\n';
      for (int j=0; j<=i; j++) {
        cout << left[j] << ' ';
      }
      cout << '\n';
      return 0;
    }
  }
}
