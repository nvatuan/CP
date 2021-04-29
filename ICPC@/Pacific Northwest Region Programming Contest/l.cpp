#include <bits/stdc++.h>
using namespace std;

long long k, p, x;

double calc(long long m) {
    return k*1.0/m*p + x*m;
}

int main() {
    cin >> k >> p >> x;
    double ans = calc(1);
    for (long long m=1; m<=(long long)(1e8)+5; m++) {
        ans = min(ans, calc(m));
    }
    cout << fixed << setprecision(3) << ans << endl;
}