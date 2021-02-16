#include <bits/stdc++.h>
using namespace std;

double EPS = (double)(1e-8);

class Point {
public:
    double x, y;
    Point() {}
    Point(double xx, double yy) : x(xx), y(yy) {}
    void input() {
        cin >> x >> y;
    }
} start1, start2, end1, end2;

double sqr(double x) { return x*x; }
double dist(Point A, Point B) {
    return sqrt(
        sqr(A.x - B.x) + sqr(A.y - B.y)
    );
}

class Segment {
public:
    double len, ang;
    Point st, en;
    Segment(Point ps, Point pe) {
        st = ps; en = pe;
        len = dist(ps, pe);
        ang = atan2(pe.y - ps.y, pe.x - ps.x);
    }
    Point interpolate(double d) {
        if (d > len) d = len;
        return Point(
            this->st.x + cos(ang)*d, this->st.y + sin(ang)*d
        );
    }
};

double distApart(Segment A, Segment B, double d) {
    return dist(A.interpolate(d), B.interpolate(d));
}

double ternary(Segment A, Segment B, double L, double R) {
    for (int i=0; i < 1000; i++) {
        double m1 = L + (R-L)/3;
        double m2 = R - (R-L)/3;
        double f1 = distApart(A, B, m1);
        double f2 = distApart(A, B, m2);
        //printf("%.6f %.6f %.6f %.6f\n", L, m1, m2, R);
        //printf("%.6f %.6f\n", f1, f2);
        if (f1 < f2) {
            R = m2;
        } else {
            L = m1;
        }
    }
    return distApart(A, B, L);
}

void solve() {
    cout << setprecision(10) << fixed;

    start1.input(); end1.input();
    start2.input(); end2.input();
    Segment A (start1, end1), B (start2, end2);

    double L = 0.0, R = max(A.len, B.len);
    cout << min(
        ternary(A, B, 0.0, min(A.len, B.len)), ternary(A, B, min(A.len, B.len), max(A.len, B.len))
    ) << '\n';
}

int main() {
    //int t; cin >> t;
    //while (t--)
        solve();
}