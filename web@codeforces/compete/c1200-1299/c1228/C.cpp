#include <bits/stdc++.h>
using namespace std;

long long n, x;

vector<int> prime(long long a) {
    vector<int> P;
    for(long long p = 2; p*p <= a; p++) {
        if( a % p == 0 ) {
            //cout << p << endl;
            P.push_back(p);
            while(a % p == 0) a /= p;
        }
    }
    if(a != 1) P.push_back(a);
    return P;
}

// vector<int> prime(long long a) {
//     int p = 2;
//     vector<int> P (0);
//     while(a >= p) {
//         if( a % p == 0 ) {
//             P.push_back(p);
//             while(a % p == 0 && a > 1) a /= p;
//         }
//         p++;
//     }
//     return P;
// }

long long fact(long long N, long long X) {
    long long result = 0;
    while(N > 0) {
        result += (N / X);
        N /= X;
    }
    return result;
}

long long expMod(long long b, long long e, long long M) {
    if( e == 0 )        return 1;
    if( e == 1 )        return b % M;
    if( e % 2 == 0 )    return expMod(b * b % M, e / 2, M);
    else                return expMod(b * b % M, e / 2, M) * b % M;
}

int main () {
    cin >> x >> n;
    //
    long long ans = 1;
    const long long M = (long long)(1e9) + 7;
    //
    vector<int> P = prime(x);
    //
    for(auto &p : P) {
        long long pwr = fact(n, p);

        long long q = pwr / M;
        long long r = pwr % M;

        ans *= expMod(p, q+r, M);
        ans %= M;
    }
    //
    cout << ans;
}