#include <bits/stdc++.h> 
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a (n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto check = [&](int x) -> bool {
        int cut = 0;
        for (int i = 0; i < n; i++) {
            cut += ((a[i] / x) + (a[i] % x != 0) - 1);
        }
        return cut <= k;
    };

    int L = 1, R = (int) 1e9;
    while (L < R) {
        int mid = L + (R - L)/2;
        if (check(mid)) {
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    cout << R << endl;
}

int main() {
    solve();
}