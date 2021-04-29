#include <bits/stdc++.h>
using namespace std;

long long a, b, c;

long long sqr(long long x) {
    return x*x;
}

int main() {
    cin >> a >> b >> c;
    cout << ((sqr(a) + sqr(b) < sqr(c) ? "Yes\n" : "No\n"));
}
