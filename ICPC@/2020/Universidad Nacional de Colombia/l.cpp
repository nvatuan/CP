#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n, m;
int sx, sy, ex, ey;
int wall[N][N];

vector< tuple<char, int, int> > dirs = {
    {'U', -1, 0}, {'D', 1, 0}, {'R', 0, 1}, {'L', 0, -1}
};

tuple<char, int, int> comeFrom[N][N];
tuple<char, int, int> nulltuple {'\0', 0, 0};

void solve() {
    sort(dirs.begin(), dirs.end());

    cin >> n >> m;
    for (int i=0; i<N; i++) fill(wall[i], wall[i] + N, 1);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            switch(c) {
                case 'S':
                    sx = i; sy = j;
                    wall[i][j] = 0;
                    break;
                case 'E':
                    ex = i; ey = j;
                    wall[i][j] = 0;
                    break;
                case '.':
                    wall[i][j] = 0;
                    break;
                default:
                    break;
            }
        }
    
    for (int i=0; i<N; i++) fill(comeFrom[i], comeFrom[i]+N, nulltuple);

    string ans_string = "";
    int ans_dist = INT_MAX;
    
    queue<tuple<int, int, int>> bfs;

    bfs.push({0, sx, sy});
    while (not bfs.empty()) {
        tuple<int, int, int> entry = bfs.front();
        bfs.pop();

        int dist = get<0>(entry);
        int X = get<1>(entry);
        int Y = get<2>(entry);

        if (X == ex and Y == ey) {
            ans_dist = dist;
            break;
        }

        for (auto tup : dirs) {
            char sign; int dx, dy;
            tie(sign, dx, dy) = tup;

            for (int cx=X+dx, cy=Y+dy; true; cx += dx, cy += dy) {
                if (0 == cx || 0 == cy || cx > n || cy > m) break;
                if (wall[cx][cy] == 0) {
                    if (comeFrom[cx][cy] == nulltuple) {
                        comeFrom[cx][cy] = make_tuple(sign, X, Y);
                        bfs.push({dist+1, cx, cy});
                    }
                    break;
                }
            }
        }
    }

    if (ans_dist == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans_dist << endl;
        ans_string = "";
        for (int x = ex, y = ey; x != sx || y != sy; ) {
            char _; tie(_, x, y) = comeFrom[x][y];
            ans_string += _;
        }
        reverse(ans_string.begin(), ans_string.end());
        cout << ans_string << endl;
    }
}

int main() {
    solve();
}