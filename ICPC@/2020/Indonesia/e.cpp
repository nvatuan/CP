#include <bits/stdc++.h>
using namespace std;

int n, k;
long long a[200000], d[200000];

int main() {
    ios::sync_with_stdio(0);

    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> d[i];

    long long ans = 0;
    for (int i=0; i<n; i++) ans += a[i];
    ans -= d[0];

    if (k > 1) { // CORRECT!!
        // lemma: it is possible to excite all atom with only min(0th -> n-2_th)
        long long sum = 0;
        for (int i=0; i<n; i++) sum += a[i];

        int min_d_among_n_1 = *min_element(d, d+n-1);
        ans = max(ans, sum - min_d_among_n_1);

        // the only case left is to excite n-1_th atom, which only affects itself
        ans = max(ans, a[n-1] - d[n-1]);
    } else { // if k is odd
        long long sum = 0;
        for (int i=0; i<n; i++) sum += a[i];
        
        // link n-2 to 0
        int min_among_n_1 = *min_element(d, d+n-1);
        ans = max(ans, sum - a[n-1] - min_among_n_1);
        ans = max(ans, sum - a[n-1] - min_among_n_1 + a[n-1] - d[n-1]); // same as above but excite the n-1_th atom
        
        // link jump skip 1 element, start at 0th
        int min_a_among_n_1 = *min_element(a+1, a+n-1);
        ans = max(ans, sum - min_a_among_n_1 - d[0]);

        // iterate start from 1-> change link at 0
        for (int i=1; i<n; i++) {
            sum -= a[i-1];
            ans = max(ans, sum - d[i]);
        }
    }
    cout << ans << '\n';
}