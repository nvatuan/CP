#include <bits/stdc++.h>
using namespace std;

const int __multitest = 0;
const int __debugmode = 0;

template<typename T>
T In() { T x; cin >> x; return x; }

// --
int n;
vector<int> a;

void solve() {
    cin >> n;
    a.resize(n);
    for (int& i : a) i = In<int>();
    //
    sort(a.begin(), a.end(), greater<int>());
    //
    int allowed_k = INT_MAX;
    long long answer = 0;

    vector<int> bit_set (62, 0);

    int sel = 0;
    vector<int> selected (n, 0);

    for (int b = 62; b >= 0; b--) {
        if ( (1LL << b) > a[0] ) continue;
        //
        int counter = 0;
        for (int i = 0; i < n; i++)
            counter += ((a[i] & (1 << b)) > 0);
        if (counter == 0) continue;

        allowed_k = min(allowed_k, counter + 2);
        if (sel < allowed_k) {
            bit_set[b] = 1;
            for (int i = 0; i < n; i++) {
                if( not selected[i] ) {
                    selected[i] = 1;
                    sel++;
                }
                if (sel == allowed_k) break;
            }
        } else break;
        //
    }
    //
    int mask;
    for (int b = 63; b >= 0; b--)
        if (bit_set[b])
            mask |= (1 << b);
    //
    for (int i = 0; i < n; i++) {

    }
}

int main() { 
    for (int t = (__multitest ? In<int>() : 1); t; t--) solve();
}