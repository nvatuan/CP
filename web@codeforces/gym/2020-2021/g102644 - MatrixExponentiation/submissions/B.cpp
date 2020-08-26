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

    void p() {
        for (int i = 0; i < this->height(); i++, cerr << '\n')
            for (int j = 0; j < this->width(); j++)
                cerr << this->data[i][j] << ' ';
    }
};

int main() {
    Matrix multi (2, 2);
    multi[0][0] = 19; multi[0][1] = 6;
    multi[1][0] = 7; multi[1][1] = 20;

    Matrix mood (1, 2);
    mood[0][0] = 1; mood[0][1] = 0;

    long long n;
    cin >> n;

    while (n > 0) {
        if (n & 1) mood = mood * multi;
        multi = multi * multi;
        n /= 2;
        // cerr << "Mood\n";
        // mood.p();
        // cerr << "Multi\n";
        // multi.p();
    }

    cout << mood[0][0] << '\n';
}