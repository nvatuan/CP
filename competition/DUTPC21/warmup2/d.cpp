#include <bits/stdc++.h>
using namespace std;

int n, t, k;
vector<vector<int>> G;

int f0[(int)(1e5)+5];

int mark[(int)(1e5)+5];

int main() {
    scanf("%d%d%d", &n, &k, &t);

    queue<pair<int, int>> Q;
    for (int i=0; i<k; i++) {
        scanf("%d", f0+i);
        Q.push({f0[i]-1, 0});
    }

    G = vector<vector<int>> (n, vector<int>());

    int m;
    scanf("%d", &m);
    while (m--) {
        int x, y; scanf("%d%d", &x, &y);
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    fill(mark, mark+n, -1);

    while (!Q.empty()) {
        auto p = Q.front(); Q.pop();
        int id = p.first;
        int fx = p.second;

        if (fx > t) continue;
        if (mark[id] != -1) continue;
        mark[id] = fx;

        for (int& nxt : G[id]) {
            Q.push({nxt, fx+1});
        }
    }

    for (int i=0; i<n; i++) {
        cout << mark[i] << ' ';
    }
    cout << endl;
}
