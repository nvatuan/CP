#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a (n);
    for (int & i : a) cin >> i;
    sort(a.begin(), a.end());

    bool possi = true;
    double f = 2.0;
    for (int i=0; i<n; i++) {
        f = min(f, a[i]*1.0/(i+1));
        if (a[i] > (i+1)) possi = false;
    }
    if (possi) cout << setprecision(7) << fixed << f << '\n';
    else cout << -1 << '\n';
}