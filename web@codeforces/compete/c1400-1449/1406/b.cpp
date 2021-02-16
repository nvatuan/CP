#include <bits/stdc++.h>
using namespace std; 

int n;
int a[int(1e5) + 10];

void solve() {
    cin >> n;
    int nPos, nNeg, nZero;
    nPos = nNeg = nZero = 0;
    for (int i=0; i<n; i++) {
        cin>>a[i];
        nPos += (a[i] > 0);
        nNeg += (a[i] < 0);
        nZero += (a[i] == 0);
    }

    sort(a, a+n);

    // case 1: prod > 0:
    long long prod = LLONG_MIN;
    if (nPos + nNeg >= 5) {
        for (int grapPos = 5; grapPos >= 1; grapPos -= 2) {
            long long sub_prod = 1;
            for (int p = 1; p <= grapPos; p++) sub_prod *= a[n-p];
            for (int ng = 1; ng <= (5 - grapPos); ng++) sub_prod *= a[ng-1];
            prod = max(prod, sub_prod);
        }
    }
    
    // case 2:
    if (nZero > 0) prod = max(prod, 0LL);
    
    // case 3: all negs
    prod = max(prod,
        1LL * a[n-1] * a[n-2] * a[n-3] * a[n-4] * a[n-5]
    );

    cout << prod << '\n';
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}