#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

const llong INF = 2e18 + 1;

struct Matrix {
    vector<vector<llong>> data;
    Matrix(int h, int w) { data = vector<vector<llong>> (h, vector<llong> (w, INF)); }

    Matrix operator*(Matrix B) {
        Matrix& A = *this;
        assert(A.getWidth() == B.getHeight());
        
        int h = A.getHeight();
        int w = B.getWidth();
        int e = A.getWidth();

        Matrix result (h, w);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                for (int k = 0; k < e; k++)
                    result[i][k] = min(result[i][k], A[i][j] + B[j][k]);
        
        return result;
    }

    int getHeight() { return data.size(); }
    int getWidth() { return data[0].size(); }
    vector<llong>& operator[](int k) { return data[k]; }
};

int n, m, k;

int main() {
    cin >> n >> m >> k;

    Matrix path (1, n); for (int i = 0; i < n; i++) path[0][i] = 0;
    Matrix edge (n, n);

    for (int u, v, c; m; m--) {
        cin >> u >> v >> c;
        edge[u-1][v-1] = c;
    }

    // while(k--) {
    //     path = path * edge;
    // }

    while (k) {
        if (k & 1) path = path * edge;
        edge = edge * edge;
        k >>= 1;
    }

    long long ans = INF;
    for (int i = 0; i < n; i++) ans = min(ans, path[0][i]);

    if (ans > (long long)(1e18)) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
}