#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int size;
    vector<int> mx;

    void init(int n) {
        for (size = 1; size < n; size <<= 1);
        mx.assign(size*2, 0);
    }

    void build(vector<int>& a, int x, int Lx, int Rx){
        if (Lx + 1 == Rx) {
            if (Lx < (int) a.size()) mx[x] = a[Lx];
            return;
        }

        int mid = (Lx + Rx)/2;
        build (a, x*2+1, Lx, mid);
        build (a, x*2+2, mid, Rx);

        mx[x] = max(mx[x*2+1], mx[x*2+2]);
    }
    void build(vector<int>& a){
        build(a, 0, 0, size);
    }

    int query(int q, int x, int Lx, int Rx){
        if (mx[x] < q) return -1;
        if (Lx + 1 == Rx) return Lx;

        int mid = (Lx + Rx)/2;
        if (mx[x*2+1] >= q) return query(q, x*2+1, Lx, mid);
        else return query(q, x*2+2, mid, Rx);
    }
    int query(int q){
        return query(q, 0, 0, size);
    }

    void update(int i, int v, int x, int Lx, int Rx){
        if (Lx + 1 == Rx) {
            mx[x] = v;
            return;
        }

        int mid = (Lx + Rx)/2;
        if (i < mid) update(i, v, x*2+1, Lx, mid);
        else update(i, v, x*2+2, mid, Rx);

        mx[x] = max(mx[x*2+1], mx[x*2+2]);
    }
    void update(int i, int v){
        update(i, v, 0, 0, size);
    }
};

int n, m;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    vector<int> a (n);
    for (int &i : a) cin >> i;

    SegmentTree st;
    st.init(n);
    st.build(a);

    while (m--) {
        int op; cin >> op;
        op--;
        if (op) {
            int query; cin >> query;
            cout << st.query(query) << endl;
        } else {
            int i, v; cin >> i >> v;
            st.update(i, v);
        }
    }
}