#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[int(1e6) + 1];

void compress() {
    map<int, int> label;
    vector<int> v (a + 1, a + n + 1);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) label[v[i]] = i+1;
    for (int i = 1; i <= n; i++) a[i] = label[a[i]];
}

int BIT[int(1e6) + 1];
void update(int x, int k) {
    for (; x <= int(1e6); x += (x & -x)) BIT[x] += k;
}
int query(int x) {
    int result = 0;
    for (; 0 < x; x -= (x & -x)) result += BIT[x];
    return result;
}
int query(int l, int r) {
    return query(r) - query(l-1);
}

int f[int(1e6) + 1];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    compress();

    for (int i = 1; i <= n; i++) update(a[i], 1);
    for (int i = 1; i <= n; i++) {
        f[i] = query(a[i] + 1, int(1e6));
        update(a[i], -1);
    }

    // for (int i = 1; i <= n; i++) {
    //     cerr << a[i] << ' ';
    // }
    // cerr << '\n';

    // for (int i = 1; i <= n; i++) {
    //     cerr << f[i] << ' ';
    // }
    // cerr << '\n';


    sort(f + 1, f + 1 + n);
    // for (int i = 1; i <= n; i++) {
    //     cerr << f[i] << ' ';
    // }
    // cerr << '\n';

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int look = k - f[i];
        int u = (lower_bound(f + i + 1, f + 1 + n, look) - (f + 1));
        // printf("i = %d u = %d\n", i, u);
        if (u < 0) continue;
        ans += (n - u);
    }
    cout << ans << '\n';
}