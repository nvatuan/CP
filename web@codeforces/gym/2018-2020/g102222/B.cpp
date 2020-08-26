#include <bits/stdc++.h>
using namespace std;

int n;

vector<pair<int, int>> P;
int X, Y;

#define x first
#define y second

inline double ang( pair<int, int> p2, pair<int, int> p1, pair<int, int> p3) {
    double a = atan2(p2.y - p1.y, p2.x - p1.x) - atan2(p3.y - p1.y, p3.x - p1.x);
    if( a < 0.0 ) a += 2*3.1415926535;
    return a;
}

inline double dist(pair<int, int> p1, pair<int, int> p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

inline double arc(double r, double theta) {
    if(theta < 0.0) theta += 2*3.1415926535;
    return r*theta;
}

void solve() {
    scanf("%d", &n);
    P = vector<pair<int, int>> (n, pair<int, int>());
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &P[i].x, &P[i].y);
    }
    cin >> X >> Y;
    // --
    double ans = 0.0;
    for(int i = 0; i < n; i++) {
        ans += ( arc(dist({X, Y}, P[i]), 3.1415926535 - ang(P[(i-1+n)%n], P[i], P[(i+1) % n])) );
    }
    printf("%.3lf\n", ans);
}

int main() {
    int T, i = 1;
    for(cin >> T; T; T--, i++) {
        printf("Case #%d: ", i);
        solve();
    }
}