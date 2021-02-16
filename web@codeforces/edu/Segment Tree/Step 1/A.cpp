#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int size;
    vector<long long> s;

    void init(int n) {
        for (size = 1; size < n; size<<=1);
        s.assign(2*size, 0LL);
    }

    void build (vector<int>& a, int x, int Lx, int Rx) {
        if (Rx - Lx == 1) {
            if (Lx < (int) a.size()) s[x] = a[Lx];
            return;
        }

        int m = Lx + (Rx - Lx) / 2;
        build (a, x*2 + 1, Lx, m);
        build (a, x*2 + 2, m, Rx);
        s[x] = s[x*2+1] + s[x*2+2];
    }

    void build(vector<int>& a) {
        build (a, 0, 0, size);
    }

    void set(int i, int v, int x, int Lx, int Rx) {
        if (Rx - Lx == 1) {
            s[x] = v;
            return;
        }

        int m = Lx + (Rx - Lx) / 2;
        if (i < m) set (i, v, x*2 + 1, Lx, m);
        else set (i, v, x*2 + 2, m, Rx);

        s[x] = s[x*2 + 1] + s[x*2 + 2];
    }

    void set(int i, int v)  {
        set(i, v, 0, 0, size);
    }

    long long sum (int l, int r, int x, int Lx, int Rx) {
        if (Lx >= r || l >= Rx) return 0;
        if (l <= Lx && Rx <= r) return s[x];

        int m = Lx + (Rx - Lx) / 2;
        long long s1 = sum (l, r, x * 2 + 1, Lx, m);
        long long s2 = sum (l, r, x * 2 + 2, m, Rx);
        return s1 + s2;
    }

    long long sum (int l, int r) {
        return sum (l, r, 0, 0, size);
    }

};

int main() {
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    SegmentTree ST;
    ST.init(n);

    vector<int> a (n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    ST.build(a);

    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int i, v;
            cin >> i >> v;
            ST.set(i, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << ST.sum(l, r) << '\n';
        }
    }
}