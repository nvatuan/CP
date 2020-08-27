#include <bits/stdc++.h>
using namespace std;

long long a[16];
int n, m;

int countBit(int x) {
    int res = 0;
    while (x > 0) {
        res += (x & 1); x >>= 1;
    }
    return res;
}

int cardinality(int state) {
    long long prod = 1;
    long long g = 0;
    for (int i = 0; i < m; i++) {
        if (state & (1 << i)) {
            if (g == 0) {
                prod *= a[i];
                g = __gcd(g, a[i]);
            } else {
                prod *= a[i];
                g = __gcd(g, a[i]);
                prod /= g;
                if (prod > n) return 0;
            }
            // cerr << prod << ' ' << g << endl;
        }
    }
    return n / prod;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i];

    long long result = 0;
    for (int state = 1; state < (1<<m); state++) {
        int bit = countBit(state);
        result += (cardinality(state) * (bit & 1 ? 1 : -1));
    }
    cout << result << '\n';
}