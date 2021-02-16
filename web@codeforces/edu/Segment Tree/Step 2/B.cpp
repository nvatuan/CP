#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int size;
    vector<int> arr;

    void init(int n) {
        for (size = 1; size < n; size *= 2);
        arr.assign(2*size, 0);
    }

    void build(vector<int>& a, int x, int Lx, int Rx) {
        if (Lx+1 == Rx) {
            if (Lx < (int) (a.size())) arr[x] = a[Lx];
            return;
        }

        int mid = (Lx + Rx) / 2;
        build (a, x*2+1, Lx, mid);
        build (a, x*2+2, mid, Rx);

        arr[x] = arr[x*2+1] + arr[x*2+2];
    }
    void build(vector<int>& a) {
        build(a, 0, 0, size);
    }

    void flip(int i, int x, int Lx, int Rx) {
        if (Lx + 1 == Rx) {
            arr[x] ^= 1;
            return;
        }

        int mid = (Lx + Rx)/2;
        if (i < mid) flip(i, x*2+1, Lx, mid);
        else flip(i, x*2+2, mid, Rx);

        arr[x] = arr[x*2+1] + arr[x*2+2];
    }
    void flip(int i) {
        flip(i, 0, 0, size);
    }

    int kth_one(int k, int x, int Lx, int Rx) {
        if (Lx + 1 == Rx) return Lx;
        
        int mid = (Lx + Rx) / 2;
        if (k <= arr[x*2+1]) return kth_one(k, x*2+1, Lx, mid);
        else return kth_one(k - arr[x*2+1], x*2+2, mid, Rx);
    }
    int kth_one(int k) {
        return kth_one(k, 0, 0, size);
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
        if (op) { // k-th one
            int k; cin >> k;
            k++;
            cout << st.kth_one(k) << endl;
        } else { // update
            int i; cin >> i;
            st.flip(i);
        }
    }
}