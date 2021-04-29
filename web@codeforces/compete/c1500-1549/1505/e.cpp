#include <bits/stdc++.h>
using namespace std;

int h, w;
char m[5][5] = {};
int c[5][5] = {};

void solve() {
    cin >> h >> w;
    for (int i=0; i<h; i++)
        for (int j=0; j<w; j++) {
            cin >> m[i][j];
        }
    

    int ans = 0;
    int cx=0, cy=0;
    while (cx < h or cy < w) {
        int flag = 0;
        // cerr << "Reset queue\n";
        queue<pair<int, int>> q;
        q.push({cx, cy});

        while (not q.empty()) {
            auto top = q.front();
            // cerr << top.first << ' ' << top.second << endl;;
            q.pop();

            if (m[top.first][top.second] == '*') {
                m[top.first][top.second] = '.';
                cx = top.first;
                cy = top.second;
                ans++;
                flag = 1;
                break;
            }

            if (top.second+1 < w) {
                if (c[top.first][top.second+1] == 0) { 
                    c[top.first][top.second+1] = 1;
                    q.push({top.first, top.second+1});
                }
            }
            if (top.first+1 < h) {
                if (c[top.first+1][top.second] == 0) { 
                    c[top.first+1][top.second] = 1;
                    q.push({top.first+1, top.second});
                }
            }
        }
        if (!flag) break;
    }
    printf("%d\n", ans);

}

int main() {
    solve();
}