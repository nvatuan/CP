#include <bits/stdc++.h>
using namespace std;

int n, k, M;

typedef long long llong;
typedef vector<vector<llong>> Matrix;
vector<vector<llong>> mat;

Matrix mul(Matrix ma, Matrix mb) {
    assert(ma[0].size() == mb.size());
    int k = ma[0].size();
    int h = ma.size();
    int w = mb[0].size();

    Matrix rs (h, vector<llong> (w, 0));
    for (int ih=0; ih<h; ih++)
        for (int iw=0; iw<w; iw++)
            for (int ik=0; ik<k; ik++) {
                rs[ih][iw] += (ma[ih][ik] * mb[ik][iw]);
                rs[ih][iw] %= M;
            }

    return rs;
}
Matrix mul(Matrix ma, llong x) {
    int h = ma.size();
    int w = ma[0].size();

    Matrix rs (h, vector<llong> (w));
    for (int ih=0; ih<h; ih++)
        for (int iw=0; iw<w; iw++) {
            rs[ih][iw] = (ma[ih][iw] * x);
            rs[ih][iw] %= M;
        }

    return rs;
}
Matrix add(Matrix ma, Matrix mb) {
    assert(ma.size() == mb.size());
    assert(ma[0].size() == mb[0].size());
    int h = ma.size(), w = ma[0].size();

    Matrix rs (ma.size(), vector<llong> (ma[0].size(), 0));
    for (int ih=0; ih < h; ih++) {
        for (int iw=0; iw < w; iw++) {
            rs[ih][iw] = ma[ih][iw] + mb[ih][iw];
            rs[ih][iw] = (rs[ih][iw] + M) % M;
        }
    }
    return rs;
}
Matrix expo(Matrix x, int k) {
    if (k == 0) return Matrix (x.size(), vector<llong> (x[0].size(), 1));

    Matrix rs (x.size(), vector<llong> (x[0].size(), 0));
    for (int i=0; i<(int)x.size(); i++) rs[i][i] = 1;
    while (k) {
        if (k & 1) rs = mul(rs, x);
        x = mul(x, x);
        k>>=1;
    }
    return rs;
}

void debug(Matrix m) {
    for (auto v : m) {  
        for (auto i : v) cout << i << ' ';
        cout << endl;
    }
}

Matrix solve(int k) {
    if (k==1) return mat;

    Matrix rs = solve(k/2);
    rs = add(rs, mul(rs, expo(mat, (k+1)/2)));

    if (k & 1) rs = add(rs, expo(mat, (k+1)/2));
    return rs;
}

int main() {
    cin >> n >> k >> M;
    mat = vector<vector<llong>> (n, vector<llong>(n, 0));
    for (auto &v : mat)
        for (auto &i : v)
            cin >> i;

    Matrix ans = solve(k);
    for (auto v : ans) {  
        for (auto i : v) cout << i << ' ';
        cout << endl;
    }
}