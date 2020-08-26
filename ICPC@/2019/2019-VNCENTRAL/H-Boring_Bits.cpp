#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

ostream& operator<<(ostream &o, vector<vector<int64>> M) {
    for(auto &v : M) {
        for(auto &i : v) {
            o << i << ' ';
        }
        o << '\n';
    }
    return o;
}

const int64 M = 666777;

vector<vector<int64>> matrixMul(vector<vector<int64>> A, vector<vector<int64>> B) {
    if( B.size() != A[0].size() ) {
        cerr << "Matrix dif size!";
        assert(0);
    }
    int64 I = A[0].size();
    int64 W = B[0].size();
    int64 H = A.size();
    // --
    vector<vector<int64>> result (H, vector<int64> (W, 0));
    for(int64 h = 0; h < H; h++)
        for(int64 w = 0; w < W; w++) 
            for(int64 i = 0; i < I; i++)
                result[h][w] = (result[h][w] + ( A[h][i] * B[i][w] )) % M;
    // --
    return result;
}

vector<vector<int64>> matrixPow(vector<vector<int64>> M, int64 e) {
    if(e == 0)  assert(0);
    if(e == 1)  return M;
    if(e & 1)   return matrixMul( matrixPow( matrixMul(M, M), e/2 ), M );
    else        return matrixPow( matrixMul(M, M), e/2 );
}

vector<vector<int64>> multiplier(int K) {
    vector<vector<int64>> M (K, vector<int64>(K, 0));
    fill(M[0].begin(), M[0].end(), 1);
    //--
    for(int i = 1; i < K; i++) M[i][i-1] = 1;
    return M;
}

vector<vector<int64>> basecase(int K) {
    vector<vector<int64>> M (K, vector<int64>(1, 0));
    if(K >= 1) M[0][0] = 1;
    if(K >= 2) M[1][0] = 1;
    return M;
}

int64 nth_K_bonacci(int K, int N) {
    auto m = multiplier(K);
    auto I = basecase(K);
    // Nth_num = m**N * I;
    // cout << m;
    // cout << "mul\n";
    // cout << I;
    return (matrixMul( matrixPow(m, N), I )[0][0]) % M;
}

int main(){
    int64 N, K;
    cin >> N >> K;
    cout << nth_K_bonacci(K+1, N);
}