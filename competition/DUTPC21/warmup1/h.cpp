#include <bits/stdc++.h>
using namespace std; 

const int THR = (int)(3e8) + 123;
bitset<THR> np;

void sieve() {
    np.set(0); np.set(1);
    for (int i=2; i<THR; i++) {
        if (!np.test(i))
            for (long long j=1LL*i*i; j<THR; j+=i)
                np.set((size_t) j, 1);
    }
}

int prime(int k) {
    return !np.test(k);
}

int main() {
    int l, r;
    cin >> l >> r;
    sieve();

    int ans=0;
    for (int i=l; i<=r; i++) {
        ans += (prime(i) && ((i % 4 == 1) || (i % 4 == 2)));
    }
    cout << ans << '\n';
}