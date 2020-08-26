#include <bits/stdc++.h>
using namespace std;

#define _USES_MATH_DEFINES

#define x first
#define y second

int main() {
    int n; cin >> n;
    vector< pair<int, int> > P (n, {0, 0});
    for(int i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y;
    }
    //
    sort(P.begin(), P.end(), [](auto a, auto b) -> int { return atan2l(a.y, a.x) < atan2l(b.y, b.x); } );

    long long answer = 0;
    for( int L = 0; L < n; L++ ) {
        long long X = P[L].x, Y = P[L].y;
        answer = max(answer, X*X + Y*Y);
        for(int i = 1; i < n; i++) {
            int R = (L + i) % n;
            X += P[R].x;
            Y += P[R].y;
            answer = max(answer, X*X + Y*Y);
        }
    }
    //
    cout << fixed << setprecision(50) << sqrtl(answer);
}