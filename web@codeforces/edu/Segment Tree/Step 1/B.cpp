#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int size;
    vector<int> mn;

    void init(int n) {
        for (size = 1; size < n; size <<= 1);
        mn = vector<int> (2*size, INT_MAX);
    }

    void build (vector<int>& a, int x, int Lx, int Rx) {
        if (Rx - Lx == 1) {
            if (Lx < (int) a.size()) mn[x] = a[Lx];
            return;
        }

        int mid = Lx + (Rx - Lx) / 2;
        build (a, x * 2 + 1, Lx, mid);
        build (a, x * 2 + 2, mid, Rx);

        mn[x] = min(mn[x*2 + 1], mn[x*2 + 2]);
    }
    void build (vector<int>& a) {
        build (a, 0, 0, size);
    }
    
    void set (int i, int v, int x, int Lx, int Rx) {
        if (Rx - Lx == 1) {
            mn[x] = v;
            return;
        }

        int mid = Lx + (Rx - Lx) / 2;
        if (i < mid) set (i, v, x * 2 + 1, Lx, mid);
        else set (i, v, x * 2 + 2, mid, Rx);

        mn[x] = min(mn[x*2+1], mn[x*2+2]);
    }
    void set (int i, int v) {
        set (i, v, 0, 0, size);
    }

    int rangeMin (int L, int R, int x, int Lx, int Rx) {
        if (R <= Lx || Rx <= L) return INT_MAX;
        if (L <= Lx && Rx <= R) return mn[x];

        int mid = Lx + (Rx - Lx) / 2;
        int mn1 = rangeMin (L, R, x * 2 + 1, Lx, mid);
        int mn2 = rangeMin (L, R, x * 2 + 2, mid, Rx);
        
        return min(mn1, mn2);
    }
    int rangeMin (int L, int R) {
        return rangeMin (L, R, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    SegmentTree ST;
    ST.init(n);

    vector<int> a (n);
    for (int &i : a) cin >> i;

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
            cout << ST.rangeMin(l, r) << '\n';
        }
    }
}