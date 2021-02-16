#include <bits/stdc++.h>
using namespace std;

class Point {
    public:
        int x, y;
        long long hash;
        Point () {}
        Point (int a, int b) : x(a), y(b) {
            hash = 1LL * x * 10000000 + y;
        }

        void p() {
            cout << "X=" << x << ";Y=" << y << endl;
        }
};

int n, m;
Point thief[2005], spotlight[2005];

const int N = 1000005;
int max_y_on_x[N];

void solve() {
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> thief[i].x >> thief[i].y;
    for (int i=0; i<m; i++) cin >> spotlight[i].x >> spotlight[i].y;

    unordered_map<long long, int> seen;
    for (int thi=0; thi<n; thi++) { // origin = thi_th thief, view from their angle
        for (int light=0; light<m; light++) {
            if (spotlight[light].x >= thief[thi].x and spotlight[light].y >= thief[thi].y) {
                Point corner[] = {
                    Point (0, spotlight[light].y - thief[thi].y),
                    Point (spotlight[light].x - thief[thi].x, 0),
                    Point (spotlight[light].x - thief[thi].x, spotlight[light].y - thief[thi].y)
                };
                for (int c=0; c<3; c++)
                    max_y_on_x[corner[c].x] = max( max_y_on_x[corner[c].x], corner[c].y+1 );
            }
        }
    }
    
    int ans = INT_MAX, y_min = 0;
    for (int x_sweep = N-1; x_sweep >= 0; x_sweep--) {
        y_min = max(y_min, max_y_on_x[x_sweep]);
        ans = min(ans, x_sweep + y_min);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    solve();    
}