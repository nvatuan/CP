#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

template <typename T>
void Print(T x, string punc = " ") {
    cout << x << punc;
}

template<typename X>
X Next() {
    X x; cin >> x; return x;
}

// -------------- -- TEMPLATE ENDS -- --------------
void solve() {
    int n = Next<int>();
    int x = Next<int>();
    vector<int> a (n);
    generate(a.begin(), a.end(), Next<int>);
    // --
    vector<int> places (202, 1);
    for (int &i : a) places[i] = 0;
    for (int i = 2; i < 202; i++) places[i] += places[i-1];
    //
    int ans = 
        (find_if(places.begin(), places.end(), [&](int y) -> bool {return y > x;}) - places.begin() - 1);
    Print(ans, "\n");

}

int main() {
    for (int t = Next<int>(); t; t--) solve();
}