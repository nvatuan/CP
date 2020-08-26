#include <bits/stdc++.h>
using namespace std;

long long x, y, R, N;

long long sqr(long long k) {
    return k*k;
}

int main() {
    cin >> x >> y >> R >> N;
    long long ans = 0;
    long long a, b;
    R *= R;

    unordered_map< double, int > ok;

    while(N--) {
        scanf("%lld%lld", &a, &b);
        double rad = atan2( b-y, a-x );
        if( ok[rad] == 0  ) {
            ok[rad] = 1;
            ans += (( sqr(a-x) + sqr(b-y) ) <= R );
        }
    }
    cout << ans;
}