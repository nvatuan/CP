#include <bits/stdc++.h>
using namespace std;

const long long M = (long long)(1e9) + 7;

int N, K;
long long prefixSum[100001];

long long x[100002];
long long mulMax[100002];
long long mulMin[100002];


long long fact[100002];

void _build_fact() {
    fact[0] = 1;
    for(int i = 1; i <= 100000; i++) fact[i] = fact[i-1] * i % M;
}

long long inv(long long x, long long y = M, long long p = 1, long long q = 0, long long r = 0, long long s = 1) {
    if(y == 0) return (p % M + M) % M;
    return inv(y, x%y, r, s, p-r*(x/y), q-s*(x/y));
}

long long C(long long n, long long k) {
    // n! / (k! * (n-k)!);
    if(k < 0) return 0;
    if(n < 0) return 0;
    if(k > n) return 0;
    if(k == n) return 1;
    return fact[n] * inv(fact[k]) % M * inv(fact[n-k]) % M;
}

int main() {
    _build_fact();
    //
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> x[i];
        prefixSum[i] = prefixSum[i-1] + x[i];
    }
    //
    sort(x + 1, x + N + 1);
    // --------------------------------------
    for(int i = 1; i <= N; i++) {
        mulMax[i] = C(i-1, K - 1);
        mulMin[i] = C(N-i, K - 1);
    }
    // // --------------------------------------
    // for(int i = 1; i <= N; i++) {
    //     cout << mulMin[i] << " ";
    // }
    // cout << endl;
    // for(int i = 1; i <= N; i++) {
    //     cout << mulMax[i] << " ";
    // }
    // cout << endl;
    //
    long long Add = 0, Minus = 0;
    for(int i = K; i <= N; i++) {
        Add = (Add + (mulMax[i] % M) * (x[i] % M)) % M;
    }
    for(int i = N-K+1; i >= 1; i--) {
        Minus = (Minus + ((mulMin[i] % M) * (x[i] % M))) % M;
    }
    cout << (Add - Minus + M) % M;
}