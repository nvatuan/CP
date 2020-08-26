#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int k;

int A[50001];

const int CELL = 225;
int sqrtDecom[CELL];

void increment(int l, int r, int k) {
    assert(l <= r);

    while (l <= r and r % CELL != (CELL - 1)) {
        A[r] += k;
        r--;
    }
    while (l <= r) {
        if (l % CELL != 0) {
            A[l] += k;
            l++;
        } else {
            sqrtDecom[l / CELL] += k;
            l += CELL;
        }
    }
}

void lazy() {
    for (int i = 0; i < n; i++) A[i] += sqrtDecom[i / CELL];
}

void generateMax() {
    for (int i = 0; i < n; i++) {
        if (i % CELL == 0) sqrtDecom[i/CELL] = 0;
        sqrtDecom[i/CELL] = max(sqrtDecom[i/CELL], A[i]);
    }
}

int query(int l, int r){
    int ans = 0;
    assert(l <= r);

    while (l <= r and r % CELL != (CELL - 1)) {
        ans = max(ans, A[r]);
        r--;
    }
    while (l <= r) {
        if (l % CELL != 0) {
            ans = max(ans, A[l]);
            l++;
        } else {
            ans = max(ans, sqrtDecom[l / CELL]);
            l += CELL;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    //
    cin >> n >> m;
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        increment(l, r, k);
        // for (int i = 0; i < n; i++) cout << i << '\t';
        // cout << endl;

        // for (int i = 0; i < n; i++) cout << A[i] << '\t';
        // cout << endl;
    }

    lazy();
    // for (int i = 0; i < n; i++) cout << A[i] << '\t';
    // cout << endl;

    generateMax();

    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(l, r) << '\n';
    }
}