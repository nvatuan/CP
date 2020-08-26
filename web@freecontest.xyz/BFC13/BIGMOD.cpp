#include <bits/stdc++.h>
using namespace std;

string A, B;
long long a, b;
long long M;

long long powMod(long long base, int exp) {
    if(exp == 0) return 1;
    if(exp == 1) return base % M;

    if(exp & 1)
        return powMod(base*base % M, exp>>1) % M * base % M;
    else
        return powMod(base*base % M, exp>>1) % M;
}

int main() {
    cin >> A >> B;
    cin >> M;
    //
    for(int i = 0; i < int(A.length()); i++) {
        a = a * 10 + (A[i] - '0');
        a %= M;
    }
    //
    long long ans = 1;
    for(int i = 0; i < int(B.length()); i++) {
        ans = powMod(ans, 10) * powMod(a, int(B[i] - '0')) % M;
    }
    //
    cout << ans;
}