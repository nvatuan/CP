#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

struct Matrix {
    vector<vector<long long>> a;
    Matrix() {}
    Matrix(int h, int w) { a = vector<vector<long long>> (h, vector<long long> (w, 0LL)); }

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

    int getHeight() { return this->a.size(); }
    int getWidth() { return this->a[0].size(); }
    vector<long long>& operator[](int k) { return this->a[k]; }

    void p() {
        int h = this->getHeight();
        int w = this->getWidth();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cerr << this->a[i][j] << ' ';
            }
            cerr << '\n';
        }
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    Matrix adja (n, n);
    for (int a, b, i = 0; i < m; i++) {
        cin >> a >> b;
        a--, b--;
        adja[a][b] = 1;
    }

    Matrix path (1, n);
    for (int i = 0; i < n; i++) path[0][i] = 1;

    while (k) {
        if (k % 2 == 1) path = path * adja;
        adja = adja * adja;
        k /= 2;
    }
    
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += path[0][i];
        if (sum >= MOD) sum -= MOD;
    }
    cout << sum << '\n';
}