#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n % 2 == 1) {
        printf("%d %d %d\n", 1, (n-1)/2, (n-1)/2);
    } else {
        if (n % 4 == 0) printf("%d %d %d\n", n/2, n/4, n/4);
        else printf("%d %d %d\n", 2, (n)/2-1, (n)/2-1);
    }
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}