#include <bits/stdc++.h>
using namespace std;

int n;

long long calc(long long x, long long y) {
    return x*x + y*y;
}

const long long INF = (long long)(5e16);

void solve() {
    vector<int> y1, y2;
    vector<int> x1, x2;
    cin >> n;
    for (int i=0; i<2*n; i++) {
        int X,Y; cin >> X >> Y;
        if (X == 0) {
            if (Y < 0) y1.push_back(-Y);
            else y2.push_back(Y);
        } else {
            if (X < 0) x1.push_back(-X);
            else x2.push_back(X);
        }
    }

    sort(y1.begin(), y1.end());
    sort(y2.begin(), y2.end());

    sort(x1.begin(), x1.end());
    sort(x2.begin(), x2.end());

    double ans = 0.0;

    int py1=0, py2=0;
    int px1=0, px2=0;
    while (py1 < y1.size() || py2 < y2.size()) {
        long long c1 = INF, c2 = INF;
        if (py1 < y1.size()) c1 = y1[py1];
        if (py2 < y2.size()) c2 = y2[py2];

        long long d1 = INF, d2 = INF;
        if (px1 < x1.size()) d1 = x1[px1];
        if (px2 < x2.size()) d2 = x2[px2];

        if (c1 < c2) {
            if (d1 < d2) {
                ans += sqrt(calc(c1, d1));
                py1++;
                px1++;
            } else {
                ans += sqrt(calc(c1, d2)); 
                py1++;
                px2++;
            }
        } else {
            if (d1 < d2) {
                ans += sqrt(calc(c2, d1));
                py2++;
                px1++;
            } else {
                ans += sqrt(calc(c2, d2)); 
                py2++;
                px2++;
            }
        }
    }

    cout << fixed << setprecision(14) << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
}