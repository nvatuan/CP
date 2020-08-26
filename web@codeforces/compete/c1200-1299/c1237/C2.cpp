#include <bits/stdc++.h>
using namespace std;

long long sqr(int x) {
    return 1LL*x*x;
}

int main() {
    int n;
    cin >> n;
    vector<Point> p;
    for(int a, b, c, i = 0; i < n; i++) {
        cin >> a >> b >> c;
        p.push_back( Point(i, a, b, c) );
    }
    // --
}