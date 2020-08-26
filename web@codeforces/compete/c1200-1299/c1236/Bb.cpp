#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int M = 1e9 + 7;

long long n, m;

long long powMod(long long b, long long e) {
    if(e == 0) return 1;
    if(e == 1) return b % MOD;
    if(e & 1) return powMod(b * b % MOD, e/2) * b % MOD;
    else return powMod(b * b % MOD, e/2);
}

int main(){
    cin >> n >> m;
    long long res = powMod(powMod(2, n), m);
    for(int i = 0; i < n; i++) {
        res -= powMod(powMod(2, i), m);
        res = (res + M) % M;
    }
    cout << res;
}