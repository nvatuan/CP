#include <bits/stdc++.h>
using namespace std;
using ll = long long; 

struct Point {
    ll x, y;
    Point(){}
    Point(ll a, ll b): x(a), y(b){};

    void read() {
        cin >> x >> y;
    }

    void print() {
        cout << "(x=" <<x << "; y=" << y<< ")\n";
    }

    ll area(const Point &p2) {
        ll dx = p2.x - this->x;
        ll dy = p2.y - this->y;
        return dx*dx + dy*dy;
    }
};

int n, k;
Point ps[200005];

unordered_map<int, vector<ll>> x_lookup;

bool exists(const Point& p) {
    if (x_lookup.find(p.x) == x_lookup.end()) return false;
    const auto& v = x_lookup[p.x];
    return binary_search(v.begin(), v.end(), p.y);
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        ps[i].read();
        x_lookup[ps[i].x].push_back(ps[i].y);
    }

    for (int i=0; i<n; i++) {
        auto &v = x_lookup[ps[i].x];
        sort( v.begin(), v.end() );
    }

    ll ans=0;
    for (int p1=0; p1<n; p1++)
        for (int p2=0; p2<n; p2++) {
            if (p1 == p2) continue;
            Point P1 = ps[p1];
            Point P2 = ps[p2];
            ll dx = ps[p1].x - ps[p2].x;
            ll dy = ps[p1].y - ps[p2].y;

            Point P3 (P1.x - dy, P1.y + dx);
            Point P4 (P2.x - dy, P2.y + dx);

            if (
                not exists(P3) or not exists(P4)
            ) continue;

            ans = max(ans, P1.area(P2));
        }
    
    cout << ans << '\n';
}
