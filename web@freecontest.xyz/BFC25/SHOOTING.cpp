#include <bits/stdc++.h>
using namespace std;

int n;
const int N = int(1e5+5);
int u[N], v[N], x[N], y[N], z[N];
int id[N];
int m;

bool hitBlock(int a, int b, int i) {
    return (
        (x[i] < a && a < u[i]) && (y[i] < b && b < v[i])
    );
}

const int INF = int(1e9);

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) {
        scanf("%d%d%d%d%d", x+i, u+i, y+i, v+i, z+i);
    }
    cin >> m;
    map<int, int> gone;
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);

        int curZ = INF;
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (gone[i]) continue;
            if (hitBlock(a, b, i)) {
                if (z[i] < curZ) {
                    curZ = z[i];
                    ans = i+1;
                }
            }
        }
        gone[ans] = true;
        printf("%d\n", ans);
    }
}

int main() {
    // int t; cin >> t;
    // while (t--)
        solve();
}                                                                                                                                                                   