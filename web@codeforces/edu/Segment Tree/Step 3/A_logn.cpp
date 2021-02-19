#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

struct SegmentTree {
    int size;
    vector<llong> arr;

    void init(int n) {
        n++;
        for (size=1; size<n; size<<=1);
        arr.assign(size*2, 0LL);
    }

    void set(int i, int x, int Lx, int Rx) {
        if (Lx + 1 == Rx) {
            arr[x] = 1;
            return;
        }

        int mid = (Lx + Rx)/2;
        if (i < mid) set (i, x*2+1, Lx, mid);
        else set (i, x*2+2, mid, Rx);

        arr[x] = arr[x*2+1] + arr[x*2+2];
    }
    void set(int i) {
        set (i, 0, 0, size);
    } 

    int inversion_of(int v, int x, int Lx, int Rx) {
        if (Rx - 1 <= v) return 0;
        if (Lx > v) return arr[x];
        int mid = (Lx + Rx) / 2;
        return inversion_of(v, x*2+1, Lx, mid) + inversion_of(v, x*2+2, mid, Rx);
    }
    int inversion_of(int v) {
        return inversion_of(v, 0, 0, size);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    SegmentTree st;
    st.init(n); 

    for (int i=0; i<n; i++) {
        cout << st.inversion_of(a[i]) << ' ';
        st.set(a[i]);
    }
    cout << endl;
    
}