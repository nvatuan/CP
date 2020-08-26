#include <bits/stdc++.h>
using namespace std;

#include <math.h>

const double EPS = 1e-7;

// -------- template ------------------------------------------
typedef double T;
struct p3 { 
    T x ,y,z;
    // Basic vector operations
    p3() { x = 0.0; y = 0.0; z = 0.0; }
    p3(T X, T Y, T Z) : x(X), y(Y), z(Z) {}

    p3 operator+(p3 p) {return {x+p.x, y+p.y, z+p.z};}
    p3 operator-(p3 p) {return {x-p.x, y-p.y, z-p.z};}
    p3 operator*(T d) {return {x*d, y*d, z*d};}
    p3 operator/(T d) {return {x/d, y/d, z/d};} // only for floating -point

    // Some comparators
    bool operator==(p3 p) {return tie(x,y,z) == tie(p.x,p.y,p.z);}
    bool operator!=(p3 p) {return !operator==(p);}

    bool operator<(p3 p)  {
        if( x < p.x ) return true;
        if( x > p.x ) return false;

        if( y < p.y ) return true;
        if( y > p.y ) return false;

        if( z < p.z ) return true;
        //if( x > p.x ) 
        return false;
    }
    bool operator<=(p3 p) {
        return (*this == p) || (*this < p);
    }
    bool operator>(p3 p)  {
        return p < *this;
    }
    bool operator>=(p3 p) {
        return (*this == p) || (*this > p);
    }
};

T operator|(p3 v, p3 w) {return v.x*w.x + v.y*w.y + v.z*w.z;}
p3 zero{0,0,0};

T sq(p3 v) {return v|v;}
double abs(p3 v) {return sqrt(sq(v));}
p3 unit(p3 v) {return v/abs(v);}

double angle(p3 v, p3 w) { 
    double cosTheta = (v|w) / abs(v) / abs(w); 
    return acos(max(-1.0, min(1.0, cosTheta))); 
}

// cross-product
p3 operator*(p3 v, p3 w) {
    return {v.y*w.z - v.z*w.y, v.z*w.x - v.x*w.z, v.x*w.y - v.y*w.x};
}

struct plane {
    p3 n; T d;
    plane() {}
    // From normal n and offset d
    plane(p3 n, T d) : n(n), d(d) {}
    // From normal n and point P
    plane(p3 n, p3 p) : n(n), d(n|p) {}
    // From three non-collinear points P,Q,R
    plane(p3 p, p3 q, p3 r) : plane((q-p)*(r-p), p) {}
    // Will be defined later: 
    // - these work with T = int
    T side(p3 p) {return (n|p)-d;}
    double dist(p3 p) {return abs(side(p))/abs(n);}
    plane translate(p3 t) {return {n, d+(n|t)};}
    // - these require T = double 
    plane shiftUp(double dist) {return {n, d + dist*abs(n)};} 

    p3 proj(p3 p) {return p - n*side(p)/sq(n);}
    p3 refl(p3 p) {return p - n*2*side(p)/sq(n);}
};


struct line3d {
    p3 d, o;
    line3d() {}
    // From two points P, Q
    line3d(p3 p, p3 q) : d(q-p), o(p) {} 
    // From two planes p1, p2 (requires T = double)
    line3d(plane p1, plane p2); // will be implemented later

    // Will be defined later:
    // - these work with T = int
    double sqDist(p3 p) {return sq(d*(p-o))/sq(d);}
    double dist(p3 p) {return sqrt(sqDist(p));}
    
    bool cmpProj(p3 p, p3 q) {return (d|p) < (d|q);}
    // - these require T = double
    p3 proj(p3 p); 
    p3 refl(p3 p); 
    p3 inter(plane p) {return o - d*p.side(o)/(p.n|d);}
};

// -----------------------------------------------------------

p3 Box[4][2];
p3 Tri[3];

//
plane BoxPlane[4];
line3d TriLine[3];

vector<p3> InterPoly;
set< vector<double> > exist;

int main() {
    for(int i = 0; i < 4; i++) {
        double x, y;
        cin >> x >> y;
        x += 100;
        y += 100;
        Box[i][0] = p3(x, y, 0.0);
        Box[i][1] = p3(x, y, 201);
    }
    for(int i = 0; i < 4; i++) {
        BoxPlane[i] = plane( Box[i][0], Box[i][1], Box[(i+1)%4][0] );
    }
    // --
    for(int i = 0; i < 3; i++) {
        double x, z;
        cin >> x >> z;
        x += 100;
        z += 100;
        Tri[i] = p3(x, 0.0, z);
    }
    for(int i = 0; i < 3; i++) {
        TriLine[i] = line3d(Tri[i], Tri[(i+1) % 3]);
        // line i-th is associated with segment { Tri[i]; Tri[(i+1) %3] }
    }


    // now get intersect point of each TriLine for each BoxPlane,
    // then check if that inter-point is on the Triangle segment
    // if it does, add it to the ``Polygon vertex''
    auto isBetween = [&](p3 a, p3 b, p3 c) -> bool {
        p3 crossprod = (b-a)*(c-a);
        if(abs(crossprod) > EPS) return false;
        //
        double dotprod   = (b-a)|(c-a);
        if( dotprod < 0.0 ) return false;
        //
        double squaredlengthba  = (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y) + (b.z - a.z)*(b.z - a.z);
        if(dotprod > squaredlengthba) {
            return false;
        }
        //
        return true;
    };

    // check if a Point is valid (not Nan, not Inf)
    auto isFinite = [&](p3 p) -> bool {
        return isfinite(p.x) && isfinite(p.y) && isfinite(p.z);
    };

    for(int tri = 0; tri < 3; tri++) {
        for(int pl = 0; pl < 4; pl++) {
            p3 c = TriLine[tri].inter(BoxPlane[pl]);
            // check if intersect is on the segment
            p3 a = Tri[tri];
            p3 b = Tri[(tri+1) % 3];
            if( isFinite(c) && isBetween(a, b, c) ) {
                vector<double> V = {c.x, c.y, c.z};
                if(exist.find(V) == exist.end()) {
                    exist.insert(V);
                    InterPoly.push_back(c);
                }
            }
        }
    }

    InterPoly.push_back(InterPoly[0]);
    // for(p3 p : InterPoly) {
    //     cout << p.x << " " << p.y << " " << p.z <<  " | " << isFinite(p) << endl;
    // }
    // --
    p3 AREAVECTOR;
    for(int i = 1; i < (int)(InterPoly.size()); i++) {
        AREAVECTOR = AREAVECTOR + (InterPoly[i-1]*InterPoly[i]);
    }
    AREAVECTOR = AREAVECTOR/2;
    //
    cout << fixed << setprecision(6) << abs(AREAVECTOR);
}