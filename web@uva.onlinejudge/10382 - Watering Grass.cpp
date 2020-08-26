#include <bits/stdc++.h>
using namespace std;

int n, l, w;
vector<pair<double, double>> seg;

bool solve() {
    seg.clear();
    if (!(cin >> n >> l >> w)) return false;
    for (int i = 0; i < n; i++) {
        double x, r; 
        cin >> x >> r;
        double dx = sqrt( max(r*r - w*w/4.0, 0.0) );
        seg.push_back({x - dx, x + dx});
    }

    // for (pair<double, double> p : seg) {
    //     printf("Lc = %.4lf Rc = %.4lf\n", p.first, p.second);
    // }
    sort(seg.begin(), seg.end());

    double Left = 0.0, Right = 0.0;
    int segUsed = 0;
    for (int i = 0; i < n && Left < l; i++) {
        if (Left < seg[i].first) {
            Left = Right;
            segUsed++;
        }
        if (seg[i].first <= Left) {
            Right = max(Right, seg[i].second);
        }
    }

    if (Left < l && Left < Right) {
        Left = Right; segUsed++;
    }

    if (Left < l) {
        printf("-1\n");
    } else {
        printf("%d\n", segUsed);
    }
    return true;
}

int main() {
    while(solve());
}