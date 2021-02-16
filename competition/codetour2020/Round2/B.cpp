#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> k;
        if (n > 12) {
            cout << 0 << endl;
        } else {
            vector<int> a;
            for (int i=0; i<n; i++) a.push_back(1);
            for (int i=0; i<n; i++) a.push_back(-1);
            int ans = 0;
            do {
                vector<int> b(n+1, 0);
                for (int i=0; i<n; i++) b[i+1] = b[i] + a[i];
                int cnt = 0;
                for (int i=1; i<n; i++) {
                    cnt += (b[i-1] <0 || b[i] < 0);
                }
                cnt += (b[1] < 0 || b[2] < 0);
                ans += (cnt == k);

            } while (next_permutation(a.begin(), a.end()));
            cout << ans << endl;
        }
    }
}