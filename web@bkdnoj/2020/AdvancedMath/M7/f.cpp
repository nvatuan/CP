#include <bits/stdc++.h>
#include <cmath>
using namespace std;

static bool DEBUG_MODE = 1;
#define db if(DEBUG_MODE)
static const double ERROR = 1e-9;

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
        printf("%.2lf %.2lf", this->x, this->y);
    }
};

int n;
vector<Point> inner_poly;
int m;
vector<Point> outer_poly;

const double INFINITE = 2001.0;
double ans;

void reset() {
    n = m = 0;
    outer_poly.resize(0);
    inner_poly.resize(0);
    ans = INFINITE;
}

void parse_input() {
    cin >> n; inner_poly.resize(n);
    for (int x, y, i = 0; i < n; i++) {
        cin >> x >> y;        
        inner_poly.at(i) = Point(x, y);
    }
    cin >> m; outer_poly.resize(m);
    for (int x, y, i = 0; i < m; i++) {
        cin >> x >> y;
        outer_poly.at(i) = Point(x, y);
    }
    // --
    auto ccw = [&](Point a, Point b, Point c) -> bool {
        return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y) >= 0;
    };
    if (ccw(inner_poly.at(0), inner_poly.at(1), inner_poly.at(2)) == false) 
        reverse(inner_poly.begin(), inner_poly.end());
    if (ccw(outer_poly.at(0), outer_poly.at(1), outer_poly.at(2)) == false) 
        reverse(outer_poly.begin(), outer_poly.end());
}

inline bool equal_with_error(double a, double b) {
    return abs(a - b) <= ERROR;
}
inline bool lesser_with_error(double a, double b) {
    return (b - a) > ERROR;
}
inline bool greater_with_error(double a, double b) {
    return (a - b) > ERROR;
}

double sqr_dist(const Point& a, const Point& b) {
    static auto sqr = [&](double x) -> double {
        return x*x;
    };
    return (sqr(a.x - b.x) + sqr(a.y - b.y));
}
double dist(const Point& a, const Point& b) {
    return sqrt(sqr_dist(a, b));
}

double tri_area (Point a, Point b, Point c) {
    return abs(a.x*b.y + b.x*c.y + c.x*a.y - a.x*c.y - b.x*a.y - c.x*b.y)/2;
}

double get_angle(const Point& b, const Point& a, const Point& c) {
    return acos( (sqr_dist(a, b) + sqr_dist(a, c) - sqr_dist(b, c)) / (2 * dist(a, b) * dist(a, c)) );
}

bool is_obtuse_angle(Point b, Point a, Point c) {
    return ((
        greater_with_error(acos( (sqr_dist(a, b) + sqr_dist(a, c) - sqr_dist(b, c)) / (2 * dist(a, b) * dist(a, c)) ), M_PI/2)
    ));
}

double get_actual_height (Point top, Point bottom1, Point bottom2) {
    double top_to_bottom1 = dist(top, bottom1);
    double top_projection = tri_area(top, bottom1, bottom2)*2/dist(bottom1, bottom2);
    double top_to_bottom2 = dist(top, bottom2);

    double min_dist = min(top_to_bottom1, top_to_bottom2);
    
    bool t_b1_b2_obtuse = is_obtuse_angle(top, bottom1, bottom2);
    bool b1_b2_t_obtuse = is_obtuse_angle(bottom1, bottom2, top);
    bool b2_t_b1_obtuse = is_obtuse_angle(bottom2, top, bottom1);

    if (
        (not equal_with_error(top_projection, 0.0))
            and
        (   (b2_t_b1_obtuse) 
                or
            (!t_b1_b2_obtuse and !b1_b2_t_obtuse and !b2_t_b1_obtuse)
        )
    )
        return min(top_projection, min_dist);
    else
        return min_dist;
}

void solve() {
    reset();
    parse_input();
    db cout << "POINT TO POINT : " << endl;
    for (int i = 0; i < outer_poly.size(); i++) {
        double MIN_DIST = INFINITE;
        int Min_idx;
        for (int j = 0; j < inner_poly.size(); j++) {
            if ( greater_with_error(MIN_DIST, dist(outer_poly[i], inner_poly[j])) ) {
                Min_idx = j;
                MIN_DIST = dist(outer_poly[i], inner_poly[j]);
            }
        }
        ans = min(ans, MIN_DIST);
        db cout << "Outer: " << i << " to Inner: " << Min_idx << " is min = " << MIN_DIST << endl;
    }
    db cout << endl;
    //
    for (int top = 0; top < n; top++) {
        double MIN_DIST = INFINITE;
        int MIN_IDX;
        for (int b1 = 0; b1 < m; b1++) {
            int b2 = (b1 + 1) % m;
            if ( greater_with_error(MIN_DIST, get_actual_height(inner_poly.at(top), outer_poly.at(b1), outer_poly.at(b2)) )) {
                MIN_IDX = b1;
                MIN_DIST = get_actual_height(inner_poly.at(top), outer_poly.at(b1), outer_poly.at(b2)); 
            }
        }
        ans = min(ans, MIN_DIST);
        db cout << "Inner: " << top << " to outer: " << MIN_IDX << ";" << (MIN_IDX+1)%m << " is min = " << MIN_DIST << endl;
    }
    db cout << endl;
    //
    for (int top = 0; top < m; top++) {
        double MIN_DIST = INFINITE;
        int MIN_IDX;
        for (int b1 = 0; b1 < n; b1++) {
            int b2 = (b1 + 1) % n;
            if ( greater_with_error(MIN_DIST, get_actual_height(outer_poly.at(top), inner_poly.at(b1), inner_poly.at(b2)))) {
                MIN_IDX = b1;
                MIN_DIST = get_actual_height(outer_poly.at(top), inner_poly.at(b1), inner_poly.at(b2));
            }
        }
        ans = min(ans, MIN_DIST);
        db cout << "Outer: " << top << " to Inner : " << MIN_IDX << ";" << (MIN_IDX+1)%n << " is min = " << MIN_DIST << endl;
    }
    db cout << endl;
    //
    printf("%.9f\n", ans/2);
}

int main() {
    DEBUG_MODE = 1;
    for (int t = In<int>(); t; t--) solve();
}