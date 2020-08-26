#include <bits/stdc++.h>
using namespace std;

const int __MULTITEST = 1;

template<typename T>
T In() { T x; cin >> x; return x; }
// --
int bits[500][500];

int sqr(int x) {
    return x*x;
}

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) fill(bits[i], bits[i] + n, 0);

    //
    int x = 0, y = 0;
    while (k > 0) {
        bits[x][y] = 1;
        x = (x + 1) % n;
        y = (y + 1) % n;
        if (bits[x][y]) {
            x++;
        }
        k--;
    }

    int maxr = 0, minr = n, maxc = 0, minc = n;
    for (int r = 0; r < n; r++) {
        int s = 0;
        for (int i = 0; i < n; i++) s += bits[r][i];
        maxr = max(maxr, s);
        minr = min(minr, s);
    }
    for (int c = 0; c < n; c++) {
        int s = 0;
        for (int i = 0; i < n; i++) s += bits[i][c];
        maxc = max(maxc, s);
        minc = min(minc, s);
    }

    cout << sqr(maxr - minr) + sqr(maxc - minc) << '\n';
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << bits[i][j];
        }
        cout << '\n';
    }
}

int main() {
    for (int t = (__MULTITEST ? In<int>() : 1); t; t--) solve();
}