#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int size;
    vector<int> mn;
    vector<int> cnt;

    void init(int n) {
        for (size = 1; size < n; size <<= 1);
        mn.assign(2*size, INT_MAX);
        cnt.assign(2*size, 0);
    }

    void build (vector<int>& a, int x, int Lx, int Rx) {
        if (Rx - Lx == 1) {
            if (Lx < (int) a.size()) {
                mn[x] = a[Lx];
                cnt[x] = 1;
            }
            return;
        }

        int mid = Lx + (Rx - Lx) / 2;
        build (a, x*2+1, Lx, mid);
        build (a, x*2+2, mid, Rx);

        mn[x] = min(mn[x*2+1], mn[x*2+2]);
        cnt[x] = 0;
        cnt[x] += (mn[x] == mn[x*2+1]) * cnt[x*2+1];
        cnt[x] += (mn[x] == mn[x*2+2]) * cnt[x*2+2];
    }
    void build (vector<int>& a) {
        build (a, 0, 0, size);
    }

    void set (int i, int v, int x, int Lx, int Rx) {
        if (Rx - Lx == 1) {
            mn[x] = v;
            cnt[x] = 1;
            return;
        }

        int mid = Lx + (Rx - Lx) / 2;
        if (i < mid) set (i, v, x*2+1, Lx, mid);
        else set (i, v, x*2+2, mid, Rx);

        mn[x] = min(mn[x*2+1], mn[x*2+2]);
        cnt[x] = 0;
        cnt[x] += (mn[x] == mn[x*2+1]) * cnt[x*2+1];
        cnt[x] += (mn[x] == mn[x*2+2]) * cnt[x*2+2];
    }
    void set (int i, int v) {
        set (i, v, 0, 0, size);
    }

    pair<int, int> query (int L, int R, int x, int Lx, int Rx) {
        if (Rx <= L || R <= Lx) return {INT_MAX, 0};
        if (L <= Lx && Rx <= R) return {mn[x], cnt[x]};
        
        int mid = Lx + (Rx - Lx) / 2;
        pair<int, int> p1 = query (L, R, x*2 + 1, Lx, mid);
        pair<int, int> p2 = query (L, R, x*2 + 2, mid, Rx);

        pair<int, int> res = {
            min(p1.first, p2.first), 0
        };

        res.second += (res.first == p1.first) * (p1.second);
        res.second += (res.first == p2.first) * (p2.second);
        return res;
    }

    pair<int, int> query (int L, int R) {
        return query (L, R, 0, 0, size); 
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
            pair<int, int> p = ST.query(l, r);
            cout << p.first << ' ' << p.second << '\n';
        }
    }
}