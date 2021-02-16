#include <bits/stdc++.h>
using namespace std;

int n, k;
int h[1000];

void solve() {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> h[i];
    }

    int ans = 0;
    for (int i=0; i<k; i++) {
        int sub_ans = 0;
        for (int i=0; i<n; i++) {
            if (i+1==n) {
                sub_ans = -1;
                break;
            }
            if (h[i] < h[i+1]) {
                sub_ans = i;
                h[i]++;
                break;
            }
        }
        ans = sub_ans;
        if (ans == -1) break;
    }
    cout << (ans > -1 ? ans+1 : ans) << '\n';
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}