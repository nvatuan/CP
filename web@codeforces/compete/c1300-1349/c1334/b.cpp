#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

template<typename T>
T In() {
    T x; cin >> x;
    return x;
}

template<typename T>
void Out(T x, string punc = "", string endln = "\n") {
    cout << x << punc << endln;

}
// ----
void solve() {
    //
    int n = In<int>();
    llong x = In<llong>();
    vector<llong> a (n + 1);
    a[0] = 0;
    generate(a.begin() + 1, a.end(), In<llong>);
    //
    sort(a.begin() + 1, a.end(), greater<llong>());
    //
    for (int i = 1; i <= n; i++) a[i] += a[i-1];
    //
    int L = 0, R = n;
    while( L < R ) {
        int mid = (L + R + 1) / 2;
        //cout << L << " " << R << "|" << mid << endl;
        if (x*mid <= a[mid]) {
            L = mid;
        } else {
            R = mid - 1;
        }
    }
    //
    Out(L);
}
// ----

int main() {
    for (int t = In<int>(); t; t--) solve();
}