#include <bits/stdc++.h>
using namespace std;

int k, n;
int a[10000];

int _init_c = false;
const int N = (int)(3e5) + 5;
long long f[N], fr[N];
long long M = (long long)(1e9) + 7;

long long binExp(long long b, long long e) {
    assert(e>=0);
    long long res = 1;
    while (e) {
        if (e&1) res = (res * b) % M;
        e >>= 1;
        b = (b * b) % M;
    }
    return res;
}

long long C(long long k, long long n) {
    if (!_init_c) {
        _init_c = true;
        f[0] = 1; for (int i=1; i<N; i++) f[i] = f[i-1] * i % M;
        for (int i=0; i<N; i++) fr[i] = binExp(f[i], M-2);
    }
    assert(k <= n);
    return f[n] * fr[k] % M * fr[n-k] % M;
}

void solve() {
    cin >> n >> k;
    for (int i=0; i<n; i++) scanf("%d", &a[i]);

    sort(a, a+n); 

    int kth = a[n-k];
    int kth_appearance = 0;
    for (int i=0; i<n; i++) kth_appearance += (a[i] == kth);
    int after_kth = n - (upper_bound(a, a+n, kth) - a);

    int unfixed = k - after_kth;
    //cerr << "After_kth: " << after_kth << endl;
    cout << C(1LL * unfixed, 1LL * kth_appearance) << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}