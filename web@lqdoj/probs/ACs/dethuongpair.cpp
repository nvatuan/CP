#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a (n);
    for (int &i : a) cin >> i;

    int p1 = 0, p2 = 1;
    tuple<int, int, int> tans {a[p2] - a[p1], p1, p2};
    for (int i=2; i<n; i++) {
        if (a[i] > a[p2]) p2 = i;
        if (a[i-1] < a[p1]) p1 = i-1;
        if (p1 >= p2) p2 = p1+1;

        tans = max(tans, make_tuple(a[p2] - a[p1], p1, p2));
    }
    cout << get<1>(tans) + 1 << ' ' << get<2>(tans) + 1 << '\n';
    cout << get<0>(tans) << '\n';
}

int main() {
    solve();
}