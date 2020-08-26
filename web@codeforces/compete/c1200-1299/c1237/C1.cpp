#include <bits/stdc++.h>
using namespace std;

long long sqr(int x) {
    return 1LL*x*x;
}

class Point {
    public:
        int idx;
        int x;
        int y;
        int z;
        Point(int i, int a, int b, int c) {
            this->idx = i;
            this->x = a;
            this->y = b;
            this->z = c;
        }
};

long long dist(const Point &A, const Point &B) {
    return sqr(A.x - B.x) + sqr(A.y - B.y) + sqr(A.z - B.z);
}

int main() {
    int n;
    cin >> n;
    vector<Point> p;
    for(int a, b, c, i = 0; i < n; i++) {
        cin >> a >> b >> c;
        p.push_back( Point(i, a, b, c) );
    }
    // --
    queue<Point> qp;
    for(int i = 0; i < n; i++) {
        qp.push( p[i] );
    }
    //
    vector<int> selected (n+1, 0);
    while( !qp.empty() ) {
        Point p1 = qp.front();
        qp.pop();
        if(selected[p1.idx]) continue;
        selected[p1.idx] = 1;
        //--
        int candidate = -1;
        long long mx = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            if( !selected[i] ) {
                if( mx > dist(p1, p[i]) ) {
                    candidate = i;
                    mx = dist(p1, p[i]);
                }
            }
        }
        selected[candidate] = 1;
        cout << p1.idx + 1 << " " << candidate + 1 << endl;
        //
    }
}