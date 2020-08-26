#include <bits/stdc++.h> 
using namespace std;
 
#ifdef LOCAL
#include "debug.hpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

const int __MULTITEST = 0;

template<typename T>
T In() { T x; cin >> x; return x; }

// ================================================= SOLUTION =================================================
class Point {
    public:
        int x, y;
        Point() {}
        Point(int a, int b) : x(a), y(b) {}

        bool operator<(const Point& o) const {
            if (this->x == o.x) {
                return this-> y < o.y;
            }
            return this->x < o.x;
        }
};

vector<Point> v (4);

void solve() {
    for (Point& p : v) {
        cin >> p.x >> p.y;
    }
    sort(v.begin(), v.end());

    auto sqr = [&](int x) -> long long {
        return 1LL * x * x;
    };

    auto dst = [&](Point a, Point b) -> long long {
        return sqr(a.x - b.x) + sqr(a.y - b.y);
    };

    // check from A
    bool flag = true;
    map<long long, int> fromA;
    for (int i = 1; i < 4; i++) {
        fromA[dst(v[0], v[i])]++;
    }
    debug(fromA);

    if (fromA.size() != 2) flag = false;
    if (fromA.begin()->first * 2 != next(fromA.begin())->first) flag = false;

    // -- ensures point with 2*a^2 away is the last point
    for (int i = 1; i < 4; i++) {
        if (dst(v[0], v[i]) == next(fromA.begin())->first) {
            swap(v[i], v[3]);
            break;
        }
    }
    // check from B and C
    if (dst(v[1], v[3]) != fromA.begin()->first) flag = false;
    if (dst(v[2], v[3]) != fromA.begin()->first) flag = false;

    cout << (flag ? "true\n" : "false\n");
}

int main() {
    for (int test = (__MULTITEST ? In<int>() : 1); test; test--) solve();
}