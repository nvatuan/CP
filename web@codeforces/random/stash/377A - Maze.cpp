#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int w[510][510];

int v[510][510];

void dfs(int x, int y) {
    if (v[x][y]) return;
    v[x][y] = 1;

    for (int id = -1; id <= 1; id++)
        for (int jd = -1; jd <= 1; jd++)
            if (id * jd == 0)
                if (!w[x + id][y + jd]) dfs(x + id, y + jd);
    if (k == 0) return;
    k--;
    w[x][y] = 2;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i <= n + 2; i++) fill(w[i], w[i] + m + 2, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0 ; j < m; j++) {
            char c; cin >> c;
            w[i+1][j+1] = (c == '#' ? 1 : 0);
        }
    
    for (int i = 1; i <= n; i++)
        for (int j = 1 ; j <= m; j++) 
            if (!w[i][j]) dfs(i, j);
    
    for (int i = 1; i <= n; i++, cout << endl)
        for (int j = 1; j <= m; j++) {
            cout << ".#X"[w[i][j]];
        }
}


int main() {
//    int t; cin >> t;
//    while(t--)
        solve();
}
