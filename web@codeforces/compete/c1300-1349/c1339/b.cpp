#include <bits/stdc++.h>
using namespace std;
typedef long long llong;

int n;
int a[100001];

int dif(int i) {
    return abs(a[i] - a[i-1]);
}

int ans[100001];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    //
    sort(a, a + n);
    int minIdx = 1;
    int idx = 0;
    int del = 0;
    //
    for (int minIdx = 2; minIdx < n; minIdx++) {
        idx = 0;
        del = 0;
        bool flag = true;
        //
        ans[idx++] = a[minIdx];
        
        int L = minIdx, R = minIdx + 1;
        while (0 < L and R < n) {
            if ( dif(L) < dif(R) ) {
                ans[idx++] = a[L-1];
                if (dif(L) < del) {
                    flag = false;
                    break;
                }
                del = dif(L);
                L--;
            } else {
                ans[idx++] = a[R];
                if (dif(R) < del) {
                    flag = false;
                    break;
                }
                del = dif(R);
                R++;
            }
        }
        while (0 < L) {
            ans[idx++] = a[L-1];
            if (dif(L) < del) {
                flag = false;
                break;
            }
            del = dif(L);
            L--;
        }
        while (R < n) {
            ans[idx++] = a[R];
            if (dif(R) < del) {
                flag = false;
                break;
            }
            del = dif(R);
            R++;
        }

        if (flag) break;
        cout << "FAILED " << minIdx << endl;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    for (cin >> t; t; t--) solve();
}