// https://open.kattis.com/problems/convexhull
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

class Point {
    public:
        int x, y;
    // --
        Point() { x = 0; y = 0; }
        Point(int a, int b) : x(a), y(b) {}
        bool operator<(Point P) {
            return ( std::make_pair(this->x, this->y) < std::make_pair(P.x, P.y) );
        }
        bool operator<(const Point P) const {
            return ( std::make_pair(this->x, this->y) < std::make_pair(P.x, P.y) );
        }
        bool operator==(Point P) {
            return (x == P.x) && (y == P.y);
        }
        bool operator==(const Point P) const {
            return (x == P.x) && (y == P.y);
        }
        Point operator-(Point P) {
            return Point(this->x - P.x, this->y - P.y);
        }
        // -- debug
        void p() {
            std::cerr << "(x = " << this->x << "; y = " << this->y << ")\n";
        }
};

long long distSqr(Point P) {
    return 1LL*(P.x)*(P.x) + 1LL*(P.y)*(P.y);
}

// --
class ConvexHull {
    public:
        std::vector<Point> convexHull;
        std::vector<Point> points;

        ConvexHull(){}
        ConvexHull(const std::vector<Point> &ps) {
            points = std::vector<Point> (ps.begin(), ps.end());
        }
    // --
        int ccw(Point a, Point b, Point c) {
            return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
        }
    // ----------------------- Andrew monotone chain algorithm
        void AndrewChain() {
            std::sort(points.begin(), points.end());
            points.erase(std::unique(points.begin(), points.end()), points.end());
            //
            if (points.size() <= 2) {
                convexHull = points;
            } else {
                int n = points.size();
                int k = 0;
                convexHull.resize( 2 * n );
                // -- construct Lower Hull and Upper Hull
                for (int i = 0; i < n; i++) {
                    while (k > 1 && ccw(convexHull[k-2], convexHull[k-1], points[i]) >= 0) k--;
                    convexHull[k++] = points[i];
                }
                for (int i = n-2, t = k; i >= 0; i--) {
                    while (k > t && ccw(convexHull[k-2], convexHull[k-1], points[i]) >= 0) k--;
                    convexHull[k++] = points[i];
                }
                convexHull.resize(k-1);
            }
        }
    // ----------------------- Graham Scan algorithm
        void GrahamScan() {
            std::sort(points.begin(), points.end());
            points.erase( std::unique(points.begin(), points.end()), points.end() );
            //
            std::sort(points.begin() + 1, points.end(), 
                [&](Point Pa, Point Pb) -> bool { 
                    int orient = ccw(points[0], Pa, Pb);
                    if (!orient) {
                        return distSqr(Pa - points[0]) < distSqr(Pb - points[0]);
                    }
                    return (orient > 0);
                } 
            );            
            
            std::stack<Point> _stack;
            _stack.push(points[0]);
            for (size_t i = 1; i < points.size(); i++) {
                // -- Pop stack and check for CCW.
                while (_stack.size() >= 2) {
                    Point mid = _stack.top();
                    _stack.pop();
                    //
                    if (  (ccw(_stack.top(), mid, points[i]) > 0) ) {
                        _stack.push(mid);
                        break;
                    }
                }
                // -- Push point if stack is under-populated or CCW is satisfied
                _stack.push(points[i]);
            }
            //
            convexHull.resize(_stack.size());
            for (size_t i = 0; !_stack.empty(); i++) {
                convexHull[i] = _stack.top();
                _stack.pop();
            }
        }
};


int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        std::vector<Point> P (n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &P[i].x, &P[i].y);
        }
        //
        ConvexHull ch (P);
        ch.GrahamScan();
        // ch.AndrewChain();

        printf("%d\n", ch.convexHull.size());
        for (int i = ch.convexHull.size() - 1; i >= 0; i--) {
            printf("%d %d\n", ch.convexHull[i].x, ch.convexHull[i].y);
        }
    }
}