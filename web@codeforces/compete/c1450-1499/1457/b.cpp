#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[(int)(1e5) + 15];

void solve() {
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int ans = INT_MAX;
    for (int c=1; c<=100; c++) {
        int subans = 0;
        for (int i=0; i<n; i++) {
            if (a[i] != c) {
                subans++;
                i += (k-1);
            }
        }
        //printf("C = %d | subans = %d\n", c, subans);
        ans = min(ans, subans);
    }
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while(t--)
        solve();
}