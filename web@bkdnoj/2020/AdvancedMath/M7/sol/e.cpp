#include <bits/stdc++.h>
#include <cmath>
using namespace std;

static bool DEBUG_MODE = 1;

template<typename T>
T In() { T x; cin >> x; return x; }

class Point {
public:
    double x, y;
    Point() { x = 0; y = 0; }
    Point(double a, double b) : x(a), y(b) {}

    Point operator+(Point rhs) {
        Point result (this->x + rhs.x, this->y + rhs.y);
        return result;
    }

    Point operator/(int dv) {
        Point result (this->x/dv, this->y/dv);
        return result;
    }

    bool operator<(Point p) {
        return ( (this->x == p.x) && (this->y < p.y) ) or 
                ( this->x < p.x );
    }

    void p() {
        printf("%.2f %.2f", this->x, this->y);
    }
};

int n;
vector<Point> points;
vector<Point> convexhull;
double rect_area_sum = 0.0;
double poly_area = 0.0;

void reset() {
    rect_area_sum = poly_area = 0.0;
    points.clear();
    convexhull.clear();
}

void parse_input() {
    reset();
    //
    n = In<int>();
    points.resize(n*4);
    for (int i = 0; i < n; i++) {
        double x, y, w, h, v;
        cin >> x >> y >> w >> h >> v;
        v *= (M_PI/180);
        rect_area_sum += (w*h);
        // --
        double hx = h * sin(v);
        double hy = h * cos(v);
        double wx = w * sin(M_PI/2 - v);
        double wy = w * cos(M_PI/2 - v);
        if (DEBUG_MODE)
            printf( "hx = %.2f\nhy = %.2f\nwx = %.2f\nwy = %.2f\n",
                hx, hy, wx, wy
            );
        //
        points[i*4 + 0] = Point(x - wx/2 - hx/2, y + wy/2 - hy/2); 
        points[i*4 + 1] = Point(x - wx/2 + hx/2, y + wy/2 + hy/2); 
        points[i*4 + 2] = Point(x + wx/2 - hx/2, y - wy/2 - hy/2); 
        points[i*4 + 3] = Point(x + wx/2 + hx/2, y - wy/2 + hy/2); 
    }
    //
    if (DEBUG_MODE) {
        cout << "Points size() = " << points.size() << endl;
        string name = "ABCDEFGHIJK";
        for (int i = 0; i < n*4; i++) {
            if (i % 4 == 0) cout << "Polygon\n";
            points[i].p();
            cout << endl;
            if (i % 4 == 3) cout << "...\n";
        }
    }
}

void compute_convex_hull() {
    convexhull.resize(0);
    // -- find anchor point, is min x and min y point
    int minxy_index = 0;
    for (int i = 1; i < points.size(); i++) {
        if ( not (points[minxy_index] < points[i]) ) minxy_index = i;
    }
    // -- set first point to be anchor point
    swap(points[0], points[minxy_index]);
    // -- sort points clockwise or cclockwise
    sort(points.begin() + 1, points.end(), [&](Point a, Point b) -> bool {
        return atan2(a.y - points[0].y, a.x - points[0].x) < atan2(b.y - points[0].y, b.x - points[0].x);
    });
    // -- graham scan
    auto ccw = [&](Point a, Point b, Point c) -> bool {
        return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y) > 0;
    };
    stack<Point> _stack;
    for (int i = 0; i < points.size(); i++) {
        if (_stack.size() < 2) _stack.push(points[i]);
        else {
            while (true) {
                Point B = _stack.top(); _stack.pop();
                if ( ccw(_stack.top(), B, points[i]) == false );
                else {
                    _stack.push(B);
                    _stack.push(points[i]);
                    break;
                }
                if (_stack.size() == 1) {
                    _stack.push(points[i]);
                    break;
                }
            }
        }
    }
    //
    while (not _stack.empty()) {
        convexhull.push_back(_stack.top());
        _stack.pop();
    }
    //
    if (DEBUG_MODE) {
        cout << "CONVEX HULL:\n";
        cout << "Polygon" << endl;
        for (Point p : convexhull) {
            p.p();
            cout << endl;
        }
        cout << "..." << endl;
    }
}

void solve() {
    parse_input();
    compute_convex_hull();
    // --
    int n_cvhull = convexhull.size();
    for (int i = 0; i < n_cvhull; i++) {
        poly_area += (convexhull[i].x*convexhull[(i+1)%n_cvhull].y - convexhull[i].y*convexhull[(i+1)%n_cvhull].x);
    }
    poly_area *= 0.5;
    poly_area = abs(poly_area);
    // -- 
    if (DEBUG_MODE) printf("POLY_AREA = %.4f\nRECT_AREA_SUM = %.4f\n", poly_area, rect_area_sum);
    printf("%.1lf %%\n", rect_area_sum/poly_area*100);
}

int main() {
    DEBUG_MODE = 0;
    for (int t = In<int>(); t; t--) solve();
}