#include <bits/stdc++.h>
using namespace std;

long long n;

int sumdig(long long x) {
    int sum = 0;
    while (x > 0) {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}

int check(long long &x) {
    long long sd = sumdig(x);
    if ( __gcd(x, sd) > 1) return 0;
    return 1;
}

void solve() {
    scanf("%lld", &n);
    while (check(n)) n++;
    printf("%lld\n", n);
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}