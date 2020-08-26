#include <bits/stdc++.h>
using namespace std;

int n, m;
int dir[102][102];
const int R = 1;
const int D = 2;
const int C = 3;

bool Lost(int x, int y) {
    if (x + 1 == n and y + 1 == m) return false;
    if (x + 1 == n and dir[x][y] == D) return true;
    if (y + 1 == m and dir[x][y] == R) return true;
    return false;
}

int ans;
int visited[102][102];
void dfs(int x, int y) {
    if (visited[x][y]) return;
    visited[x][y] = true;

    if (Lost(x, y)) {
        //cerr << "@" << x << " " << y << endl;
        if (dir[x][y] == R) dir[x][y] = D;
        else if (dir[x][y] == D) dir[x][y] = R;
        ans++;
    }
    if (dir[x][y] == R) dfs(x, y+1);
    if (dir[x][y] == D) dfs(x+1, y);
    return;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            switch (c) {
                case 'R':
                    dir[i][j] = R; break;
                case 'D':
                    dir[i][j] = D; break;
                case 'C':
                    dir[i][j] = C; break;
            }
        }

    for (int i = 0; i < n; i++) fill(visited[i], visited[i] + 102, 0);
    ans = 0;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            if (!visited[i][j])
                dfs(i, j);
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}