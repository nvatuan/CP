#include <bits/stdc++.h>
using namespace std;

int n, m;
char g[2005][2005];
int c[2005][2005];
int dn[2005][2005];

int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) {
                char c; cin >> c;
                g[i][j] = c;
        }

    for (int i=0; i<=m+1; i++) {
        c[0][i] = 1;
        c[n+1][i] = 1;
    }
    for (int i=0; i<=n+1; i++) {
        c[i][0] = 1;
        c[i][m+1] = 1;
    }

    
    queue<tuple<int, int, int>> Q[2];
    int flip=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) {
            if (g[i][j] == '.') {
                Q[flip].push(make_tuple(i, j, 0));
            }
        }

    while (true) {
        while (!Q[flip].empty()) {
            auto top = Q[flip].front(); Q[flip].pop();
            int x, y, d;
            tie(x, y, d) = (top);

            if (c[x][y]) continue;
            c[x][y] = 1;
            dn[x][y] = d;

            for (int dx:{-1,0,1}) {
                for (int dy:{-1,0,1}) {
                    if (c[x+dx][y+dy]) continue;
                    if (g[x+dx][y+dy] == g[x][y]) {
                        Q[flip].push({x+dx,y+dy,d});
                    } else {
                        Q[flip^1].push({x+dx,y+dy,d+1});
                    }
                }
            }
        }
        flip ^= 1;
        if (Q[flip].empty()) break;
    }

    // for (int i=1; i<=n; i++) {
    //     for (int j=1; j<=m; j++) {
    //         cout << dn[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    map<char, int> rs;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) {
            if (rs.find(g[i][j]) == rs.end()) {
                rs[g[i][j]] = dn[i][j];
            } else {
                rs[g[i][j]] = min(rs[g[i][j]], dn[i][j]);
            }
        }
    for (auto p : rs) {
        char c = p.first;
        if (!(isalpha(c) && isupper(c))) continue;
        printf("%c %d\n", c, p.second-1);
    }
}
