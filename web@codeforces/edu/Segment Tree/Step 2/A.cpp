#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long ans, pref, suf, sum;

    Node () {
        this->assign(0);
    }

    void assign(int x) {
        sum = (long long)(x);
        ans = pref = suf = max(0LL, sum);
    }

    void merge(Node& left, Node& right) {
        this->ans = max({left.ans, right.ans, 0LL});
        this->ans = max(left.suf + right.pref, this->ans);
        this->ans = max ({
            left.ans, right.ans, left.suf + right.pref, 0LL
        });

        this->suf = max({
            left.suf + right.sum, right.suf, 0LL
        });

        this->pref = max({
            left.pref, left.sum + right.pref, 0LL
        });
        this->sum = left.sum + right.sum;
    }
};

struct SegmentTree {
    int size;
    vector<Node> arr;

    void init(int n) {
        for (size = 1; size < n; size <<= 1);
        arr.assign(2 * size, Node());
    }

    void build (vector<int>& a, int x, int Lx, int Rx) {
        if (Rx - Lx == 1) {
            if (Lx < (int) a.size()) {
                arr[x].assign(a[Lx]);
            }
            return;
        }

        int mid = Lx + (Rx - Lx)/2;
        build (a, x*2+1, Lx, mid);
        build (a, x*2+2, mid, Rx);
        // merge
        arr[x].merge(arr[x*2+1], arr[x*2+2]);
    }

    void build(vector<int>& a) {
        build (a, 0, 0, size);
    }

    void set(int i, int v, int x, int Lx, int Rx) {
        if (Rx - Lx == 1) {
            arr[x].assign(v);
            return;
        }

        int mid = Lx + (Rx - Lx)/2;
        if (i < mid) set (i, v, x*2+1, Lx, mid);
        else set (i, v, x*2+2, mid, Rx);
        arr[x].merge(arr[x*2+1], arr[x*2+2]);
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    long long max_segment() {
        return arr[0].ans;
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int &i : a) cin >> i;

    SegmentTree ST;
    ST.init(n);
    ST.build(a);

    cout << ST.max_segment() << '\n';
    while (m--) {
        int i, v;
        cin >> i >> v;
        ST.set(i, v);
        cout << ST.max_segment() << '\n';
    }
}