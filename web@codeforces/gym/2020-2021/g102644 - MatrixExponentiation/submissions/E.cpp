#include <bits/stdc++.h>
using namespace std;

typedef long long llong;
typedef unsigned long long ullong;

const long long MOD = 4294967296LL;

struct Matrix {
    vector<vector<ullong>> data;
    Matrix() {}
    Matrix(int h, int w) { data = vector<vector<ullong>> (h, vector<ullong> (w, 0)); }

    Matrix operator*(Matrix B) {
        Matrix& A = *this;
        assert(A.getWidth() == B.getHeight());

        int h = A.getHeight();
        int w = B.getWidth();
        int e = A.getWidth();

        Matrix result (h, w);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                for (int k = 0; k < e; k++) {
                    result[i][j] += (A[i][k] * B[k][j]);
                    result[i][j] %= MOD;
                }
        return result;
    }

    int getHeight() { return this->data.size(); }
    int getWidth() { return this->data[0].size(); }
    vector<ullong>& operator[] (int k) { return data[k]; }
};

Matrix path (1, 65);
Matrix connect (65, 65);
const int VOID = 64;

void init() {
    static int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    static int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    static auto valid = [&](int x, int y) -> bool {
        return (0 <= x && x < 8) and (0 <= y && y < 8);
    };
    static auto getIndex = [&](int x, int y) -> int { 
        return (x * 8 + y);
    };

    for (int ki = 0; ki < 8; ki++) {
        for (int kj = 0; kj < 8; kj++) {
            for (int off = 0; off < 8; off++) {
                int kX = ki + dx[off], kY = kj + dy[off];
                if (not valid(kX, kY)) continue;

                connect[getIndex(kX, kY)][getIndex(ki, kj)] = 1;
            }
            connect[getIndex(ki, kj)][VOID] = 1;
        }
    }
    connect[VOID][VOID] = 1;
    path[0][0] = 1;
}


int main() {
    init();
    int k; cin >> k;
    // while (k--) {
    //     path = path * connect;
    // }
    while (k) {
        if (k & 1) path = path * connect;
        connect = connect * connect;
        k >>= 1;
    }


    ullong ans = 0;
    for (int i = 0; i < path.getWidth(); i++) {
        ans += path[0][i];
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans << endl;
}