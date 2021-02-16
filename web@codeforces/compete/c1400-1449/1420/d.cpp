#include <bits/stdc++.h>
using namespace std;

int n, k;
int l[300010], r[300010];

const int MOD = 998244353;
const int N = 300010;

long long f[N];
void precomp() {
    f[0] = 1;
    for (int i=1; i<N; i++) f[i] = f[i-1]*i % MOD;
}

long long binExp(long long b, int e) {
    long long result = 1;
    while (e > 0) {
        if (e & 1) result = result * b % MOD;
        e >>= 1;
        b = b * b % MOD;
    }
    return result;
}
long long C(long long k, long long n) {
    if (k > n) return 0;
    return f[n] * binExp(f[k], MOD-2) % MOD * binExp(f[n-k], MOD-2) % MOD;
}


void solve() {
    precomp();
    cin >> n >> k;
    vector<int> ends;
    for (int i=0; i<n; i++) {
        cin >> l[i] >> r[i];
        ends.push_back(+l[i]);
        ends.push_back(-(r[i]+1));
    }
    sort(ends.begin(), ends.end(), [&](int a, int b)->bool {
        if (abs(a) == abs(b)) {
            return a < b;
        }
        return abs(a) < abs(b);
    });
    //for (int x : ends) cout << x <<  ' ';
    //cout << endl;

    long long ans = 0;
    int overlap = 0;

    for (int x : ends) {
        if (x > 0) {
            overlap++;
            if (overlap >= k) {
                ans = (ans + C(k-1, overlap - 1));
                ans = (ans >= MOD ? ans - MOD : ans);
            }
        } else overlap--;
    }

    cout << ans << endl;
}

int main() {
    //int t; cin >> t;
    //while (t--)
        solve();
}