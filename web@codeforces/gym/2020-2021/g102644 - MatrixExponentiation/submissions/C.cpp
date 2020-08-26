#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

struct Matrix {
    vector<vector<long long>> data;
    Matrix (int h, int w) { data = vector<vector<long long>> (h, vector<long long> (w, 0)); }
    // -- function
    int height() { return data.size(); }
    int width() { return data[0].size(); }

    Matrix operator*(Matrix B) {
        Matrix& A = *this;
        assert(A.width() == B.height());
        int edge = A.width();

        Matrix result (A.height(), B.width());
        for (int i = 0; i < A.height(); i++) {
            for (int j = 0; j < B.width(); j++) {
                for (int k = 0; k < edge; k++) {
                    result[i][j] += A[i][k] * B[k][j];
                    result[i][j] %= MOD;
                }
            }
        }

        return result;
    }
    
    vector<long long>& operator[](int k) { return data[k]; }
};

int main() {
    Matrix multi (2, 2);
    multi[0][0] = 0; multi[0][1] = 1;
    multi[1][0] = 1; multi[1][1] = 1;

    Matrix fibo (1, 2);
    fibo[0][0] = 0; fibo[0][1] = 1;

    long long n;
    cin >> n;

    while (n > 0) {
        if (n & 1) fibo = fibo * multi;
        multi = multi * multi;
        n /= 2;
    }

    cout << fibo[0][0] << '\n';
}