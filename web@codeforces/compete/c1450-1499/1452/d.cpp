#include <bits/stdc++.h>
using namespace std;

long long MOD = 998244353;

long long binExp(long long b, long long e) {
    if (e == 0) return 1;
    long long res = 1;
    while (e) {
        if (e & 1) res = res * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return res;
}

long long fibo(int n) {
    if (n <= 2) return 1;
    int f[2] = {1, 1};
    n -= 2;
    while (n--) {
        int a = f[1];
        f[1] = (f[0] + f[1]) % MOD;
        f[0] = a;
    }
    return f[1];
}

void solve() {
    int n; cin >> n;
    long long F = fibo(n);
    //for (int i = 1; i <= 10; i++) cout << fibo(i) << endl;
    cout << F * binExp(binExp(2, n), MOD-2) % MOD << '\n';
}

int main() {
    // int t; cin >> t;
    // while(t--)
        solve();
}