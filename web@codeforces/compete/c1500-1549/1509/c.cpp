#include <bits/stdc++.h>
using namespace std;

multiset<int>::iterator find_near_max(multiset<int>& ms, int x) {
    if (ms.size() == 1) return ms.begin();

    auto it = ms.lower_bound(x);
    if (it == ms.end()) it = prev(it);
    return it;
}

multiset<int>::iterator find_near_min(multiset<int>& ms, int x) {
    if (ms.size() == 1) return ms.begin();

    auto it = ms.lower_bound(x);
    if (it == ms.begin()) return it;
    it = prev(it);
    return it;
}

long long greedy(multiset<int>& a, int start) {
    long long d=0;
    int mx = start, mn = start;
    while (!a.empty()) {
        auto it1 = find_near_max(a, mx);
        auto it2 = find_near_min(a, mn);
        if (abs(start - *it1) < abs(start - *it2)) {
            mx = max(mx, *it1);
            mn = min(mn, *it1);
            a.erase(it1);
        } else {
            mx = max(mx, *it2);
            mn = min(mn, *it2);
            a.erase(it2);
        }
        fprintf(stderr, "Max=%d Min=%d\n", mx, mn);
        d += (mx - mn);
    }
    return d;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a (n);
    for (int &i : a) cin >> i;

    long long ans = LLONG_MAX;
    for (int i=2; i<3; i++) {
        multiset<int> l;
        for (int j=0; j<n; j++) if (j != i) l.insert(a[j]);
        ans = min(ans, greedy(l, a[i]));
    }
    cout << ans << endl;
}

int main() {
    solve();
}