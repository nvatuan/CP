#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    vector<int> a (n);
    for (int &i : a) cin >> i;
    a.push_back((int)1e9 + 3);
    n++;

    sort(a.begin(), a.end());
    
    vector<int> same;
    vector<int> dif;
    for (int l=0, i=1; i<n; i++) {
        if (a[i-1] != a[i]) {
            same.push_back(i-l);
            dif.push_back(a[i] - a[i-1]);
            l = i;
        }
    }

    int L = 0, R = (int) same.size() - 1;
    int pL = 0, pR = 0;
    int cost = a[n-2] - a[0];

    for (int i : same) cout << i << ' ';
    cout << endl;
    for (int i : dif) cout << i << ' ';
    cout << endl;

    while (L < R && (k >= 1LL*(pL + same[L]) * dif[L] || k >= (pL + same[R]) * dif[R-1])) {
        printf("L=%d, R=%d | k=%d\n", L, R, k);
        printf("pL=%d, pR=%d\n", pL, pR);
        if ( 1LL*(pL + same[L]) * dif[L] < 1LL*(pR + same[R]) * dif[R-1]) {
            pL += same[L];
            k -= pL * dif[L];
            cost -= dif[L];
            L++;
        } else {
            pR += same[R];
            k -= pR * dif[R-1];
            cost -= dif[R-1];
            R--;
        }
    }
    if (k>0 and L < R) {
        if ( 1LL*(pL + same[L]) * dif[L] < 1LL*(pR + same[R]) * dif[R-1]) {
            cost -= (k / pL + same[L]);
        } else {
            cost -= (k / pR + same[R]);
        }
    }
    printf("L=%d, R=%d | k=%d\n", L, R, k);
    printf("pL=%d, pR=%d\n", pL, pR);

    cout << cost << '\n';
}