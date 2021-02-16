#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long p = 1;
    for (int i=2; i<=n; i++) {
        p = p * i / __gcd(p, 1LL*i);
    }
    cout << p+1 << '\n';
}