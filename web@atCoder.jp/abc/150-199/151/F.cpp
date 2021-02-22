#include <bits/stdc++.h>
using namespace std;

class Point {
    public:
        int x = 0;
        int y = 0;
};

int N;
vector< Point > P;

// minEnclose returns squared the minimum radius of the circle that:
// Has P1, P2 on its circumfence and
// Encloses all N Points
const double Eps = 1e-9;

template<typename T>
T sqr(T x) {
    return x*x;
}

// https://math.stackexchange.com/questions/1781438/finding-the-center-of-a-circle-given-two-points-and-a-radius-algebraically

bool enclosedAll(double R, Point P1, Point P2) {
    // calculate Circle's Origin; it does not have to be integer
    double Mx = abs(P1.x - P2.x)*1.0/2;
    double My = abs(P1.y - P2.y)*1.0/2;
    double Sa = sqr(P1.x - Mx) + sqr(P1.y - My);
    double b  = sqrt(sqr(R) - Sa);

    double delx = P1.x - P2.x;
    double dely = P1.y - P2.y
    double Ox   = 
    //

}

double minEnclose(Point P1, Point P2) {
    // By doing a binary search on its Radi, we can approach a R that almost not enclose every points
    // since its either YES (encloses all) or NO (not encloses all) by doing a O(N) check.
    // complexity: O(N*N) * O(N*log2(sqrt( (1000**2) * 2)) (not how correct BigO notation should be used, i am aware.)
    double rL = 0.0;
    double rR = sqrt( (1000*1000)*2 );
    while( rR - rL > Eps ) {
        double rMid = (rL + rR)/2;
        //
        if( enclosedAll(rMid, Point P1, Point P2) ) {

        } else {

        }
    }
}

int main() {
    cin >> N;
    P.resize(N, Point() );
    for(int i = 0; i < N; i++) {
        cin >> P[i].x >> P[i].y;
    }
    // --
    double minSqrRadi = sqrt((1001*1001)*2); // with given contraints, R couldnt reach this much
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            minSqrRadi = min(minSqrRadi, minEnclose(P[i], P[j]));
        }
    }
}