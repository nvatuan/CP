#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int size;
    vector<int> arr;

    void init(int n) {
        size = n;
        arr.assign(size+1, 0);
    }

    void update (int i, int v) {
        i++;
        for (; i <= size; i += (i & (-i))) arr[i] += v;
    }

    int sum (int x) {
        int res = 0;
        for (; x > 0; x -= (x & (-x))) res += arr[x];
        return res;
    }
    int sum (int lx, int rx) {
        return sum(rx) - sum (lx-1);
    }

    void build (vector<int>& a) {
        for (int i=0; i<size; i++) update(i, a[i]);
    }
};

int n, m;
vector<int> a;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    a.resize(n);
    for (int i=0; i<n; i++) cin >> a[i];

    Fenwick fw;
    fw.init(n);
    fw.build(a);

    // for (int i=0; i<=n; i++) {
    //     cerr << fw.arr[i] << ' ';
    // }
    // cerr << endl;
    // for (int i=0; i<=n; i++) {
    //     cerr << fw.sum(i) << ' ';
    // }
    // cerr << endl;

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i; cin >> i;
            if (a[i]) fw.update(i, -1);
            else fw.update(i, 1);
            a[i] ^= 1;
        } else {
            int k; cin >> k;
            k+=1;
            int l = 0, r = n;
            while (l + 1 < r) {
                int mid = l + (r-l)/2;
                if (fw.sum(mid) >= k) r = mid;
                else l = mid;
            }
            cout << r-1 << '\n';
        }
    }
}