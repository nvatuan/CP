#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

int n, l;
int a[200000];

double ans;

void solve() {
    cin >> n >> l;
    for (int i=1; i<=n; i++) cin >> a[i];
    a[0] = 0;
    a[n+1] = l;
    ans = 0.0;
    //
    vector<pair<double, int>> checkpoint_car1 (n+2, {0.0, 1}), checkpoint_car2 (n+2, {0.0, 1});
    // car 1
    int x = 0; int v = 1;
    double total_time = 0.0;
    for (int i=1; i<=n+1; i++) {
        int d = (a[i] - x);
        double time = (double) d / v;

        total_time += time;
        v++;
        x = a[i];

        checkpoint_car1[i] = {total_time, v};
    }

    x = l; v = 1;
    total_time = 0.0;
    for (int i=n; i>=0; i--) {
        int d = (x - a[i]);
        double time = (double) d / v;

        total_time += time;
        v++;
        x = a[i];

        checkpoint_car2[i] = {total_time, v};
    }

    int L = 0, R = 1;
    for (int i=0; i<=n+1; i++) {
        if (checkpoint_car1[i].first + EPS < checkpoint_car2[i].first) continue;
        L = i-1;
        R = i;
        break;
    }

    //cout << "Found: " << L <<  ' ' << R  << endl;
    double d_x1 = 0;
    double d_x2 = (a[R] - a[L]);
    double t1 = checkpoint_car1[L].first;
    double v1 = checkpoint_car1[L].second;
    double t2 = checkpoint_car2[R].first;
    double v2 = checkpoint_car2[R].second;
    //cout << d_x1 << ' ' << d_x2 << endl;
    //cout << t1 << ' ' << t2 << endl;
    if (t1 + EPS <= t2) {
        d_x1 = (t2 - t1) * v1;
        t1 = t2;
    } else {
        d_x2 -= (t1 - t2) * v2;
    }
    cout << t1 + (d_x2 - d_x1)/(v1+v2) << '\n';
}

int main() {
    cout << setprecision(9) << fixed;
    int t; cin >> t;
    while (t--)
        solve();    
}