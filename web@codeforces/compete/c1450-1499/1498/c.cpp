#include <bits/stdc++.h>
using namespace std;

const int MOD = (1e9) + 7;
int n, k;

void solve() {
    cin >> n >> k;

    if (k == 1) {
        cout << 1 << endl;
        return;
    }
    if (n == 1) {
        cout << 2 << endl;
        return;
    }

    long long ans=0;
    vector<int> plane(n, 0); 

    plane[0] = 1;
    for (int i=0; i<k; i++) {
        if (!(i&1)) {
            for (int p=0; p<n; p++) {
                if (p+1==n) {
                    ans += plane[p];
                    ans %= MOD;

                    plane[p-1] += plane[p];
                    plane[p-1] %= MOD;

                    plane[p] = 0;
                } else {
                    if (p == 0) {
                        ans += plane[p];
                        ans %= MOD;
                    } else {
                        plane[p-1] += plane[p];
                        plane[p-1] %= MOD;
                    }
                    plane[p+1] += plane[p];
                    plane[p+1] %= MOD;
                    plane[p] = 0;
                }
            }
        } else {
            for (int p=n-1; p>=0; p--) {
                if (p == 0) {
                    ans += plane[p];
                    ans %= MOD;

                    plane[p+1] += plane[p];
                    plane[p+1] %= MOD;

                    plane[p] = 0;
                } else {
                    if (p+1==n) {
                        ans += plane[p];
                        ans %= MOD;
                    } else {
                        plane[p+1] += plane[p];
                        plane[p+1] %= MOD;
                    }
                    plane[p-1] += plane[p];
                    plane[p-1] %= MOD;
                    plane[p] = 0;
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}