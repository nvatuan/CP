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
    vector<int> p (n), c(n);
    for (int i = 0; i < n; i++ ) 
        cin >> p[i] >> c[i];
    //
    bool flag = true;
    int P = -1, C = -1;
    for (int i = 0; i < n; i++ ) {
        flag &= (p[i] >= c[i]);
        flag &= (p[i] >= P);
        flag &= (c[i] >= C);
        
        flag &= (c[i] - C <= p[i] - P);

        P = p[i];
        C = c[i];
    }
    //
    cout << (flag ? "YES\n" : "NO\n");
}
// ----

int main() {
    for (int t = In<int>(); t; t--) solve();
}