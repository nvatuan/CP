#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

struct SegmentTree {
    int size;
    vector<llong> s;

    void init(int n) {
        n++;
        for (size = 1; size < n; size <<= 1);
        s.assign(size*2, 0LL);
    }

    void set(int i, int x, int Lx, int Rx){
        if (Lx + 1 == Rx) {
            s[x] = 1;
            return;
        }
        int mid = (Lx + Rx)/2;
        if (i < mid) set(i, x*2+1, Lx, mid);
        else set (i, x*2+2, mid, Rx);
        s[x] = s[x*2+1] + s[x*2+2];
    }
    void set(int i){
        set(i, 0, 0, size);
    }

    llong not_greater_than(int v, int x, int Lx, int Rx) {
        if (Rx - 1 <= v) return s[x];
        else {
            if (Lx > v) return 0LL;
            else {
                int mid = (Lx + Rx)/2;
                return not_greater_than(v, x*2+1, Lx, mid) + not_greater_than(v, x*2+2, mid, Rx);
            }
        }
    }
    llong not_greater_than(int v) {
        return not_greater_than(v, 0, 0, size);
    }
};

int main() {
    int n; cin >> n;
    vector<int> a (n);
    for (int &i : a) cin >> i;

    SegmentTree st;
    st.init(n);

    for (int i : a) {
        cout << st.not_greater_than(n) - st.not_greater_than(i) << ' ';
        st.set(i);
    }
}