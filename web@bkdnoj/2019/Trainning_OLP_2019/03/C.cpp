#include <bits/stdc++.h>
using namespace std;

int n;
int a, b, x, y;

vector<vector<int>> edge;

typedef long long int64;
#define X first
#define Y second

class rec {
    public:
        pair<int, int> ld, lu, rd, ru;
        rec(){}
        rec(pair<int, int> ld, pair<int, int> lu, pair<int, int> rd, pair<int, int> ru){
            this->ld = ld;
            this->lu = lu;
            this->rd = rd;
            this->ru = ru;
        };
};

bool cmp(rec A, rec B) {
    if(A.ld.X < B.ld.X) return 1;
    if(A.ld.X > B.ld.X) return 0;
    return A.ld.Y < B.ld.Y;
}

vector< rec > R;

bool intersec(int sx, int sy, int r) {
    if( x < R[r].ld.X  || y < R[r].ld.Y ) return 0;
    if( R[r].ru.X < sx || R[r].ru.Y < sy ) return 0;
    //
    int LD, LU, RD, RU;
    LD = LU = RD = RU = 0;
    LD |= ((R[r].ld.X < sx) << 3);
    LD |= ((R[r].ld.Y < sy) << 2);
    LD |= ((R[r].ld.X < x) << 1);
    LD |= ((R[r].ld.Y < y) << 0);
    //
    LU |= ((R[r].lu.X < sx) << 3);
    LU |= ((R[r].lu.Y < sy) << 2);
    LU |= ((R[r].lu.X < x) << 1);
    LU |= ((R[r].lu.Y < y) << 0);
    //
    RD |= ((R[r].rd.X < sx) << 3);
    RD |= ((R[r].rd.Y < sy) << 2);
    RD |= ((R[r].rd.X < x) << 1);
    RD |= ((R[r].rd.Y < y) << 0);
    //
    RU |= ((R[r].ru.X < sx) << 3);
    RU |= ((R[r].ru.Y < sy) << 2);
    RU |= ((R[r].ru.X < x) << 1);
    RU |= ((R[r].ru.Y < y) << 0);
    //
    return !(LD == LU && LU == RD && RD == RU);
}

double ans = (1<<20)*1.0;

int main() {
    cin >> n >> a >> b >> x >> y;
    if( x < a ) {
        swap(a, x);
        swap(b, y);
    }
    edge    = vector<vector<int>> (n, vector<int>());
    // --
    R = vector<rec> (n, rec());
    for(int ax, bx, ay, by, i = 0; i < n; i++) {
        cin >> ax >> ay >> bx >> by;
        R[i] = rec( {ax, by}, {ax, ay}, {bx, by}, {bx, ay} );
    }
    // --
    sort(R.begin(), R.end(), cmp);
    // --
    queue< pair<double, pair<int, int>> > Q;
    Q.push( {0.0, {a, b}} );
    //
    int flag = 0;
    vector<int> check (n, 0);
    while( !Q.empty() ) {
        flag = 0;
        double path = Q.front().first;
        int     a   = Q.front().second.first;
        int     b   = Q.front().second.second;
        //printf("%d, %d -> %.3lf\n", a, b, path);
        Q.pop();
        // --
        for(int i = 0; i < n; i++) {
            if( intersec(a, b, i) ) {       // WRONG!!
                // Q.push( { hypot(R[i].ld.X - a, R[i].ld.Y - b) + path, {R[i].ld.X, R[i].ld.Y} } );        
                // Q.push( { hypot(R[i].rd.X - a, R[i].rd.Y - b) + path, {R[i].rd.X, R[i].rd.Y} } );        
                // Q.push( { hypot(R[i].lu.X - a, R[i].lu.Y - b) + path, {R[i].lu.X, R[i].lu.Y} } );        
                // Q.push( { hypot(R[i].ru.X - a, R[i].ru.Y - b) + path, {R[i].ru.X, R[i].ru.Y} } );        
                if(a < R[i].ld.X) {
                    if(b < R[i].ld.Y) {
                        flag = 1;
                        Q.push( { hypot(R[i].ld.X - a, R[i].ld.Y - b) + path, {R[i].ld.X, R[i].ld.Y} } );        
                        Q.push( { hypot(R[i].lu.X - a, R[i].lu.Y - b) + path, {R[i].lu.X, R[i].lu.Y} } );        
                        Q.push( { hypot(R[i].rd.X - a, R[i].rd.Y - b) + path, {R[i].rd.X, R[i].rd.Y} } );   
                    } else if(b > R[i].lu.Y) {
                        flag = 1;
                        Q.push( { hypot(R[i].ld.X - a, R[i].ld.Y - b) + path, {R[i].ld.X, R[i].ld.Y} } );        
                        Q.push( { hypot(R[i].lu.X - a, R[i].lu.Y - b) + path, {R[i].lu.X, R[i].lu.Y} } );        
                        Q.push( { hypot(R[i].ru.X - a, R[i].ru.Y - b) + path, {R[i].ru.X, R[i].ru.Y} } );        
                    } else {
                        flag = 1;
                        Q.push( { hypot(R[i].ld.X - a, R[i].ld.Y - b) + path, {R[i].ld.X, R[i].ld.Y} } );        
                        Q.push( { hypot(R[i].lu.X - a, R[i].lu.Y - b) + path, {R[i].lu.X, R[i].lu.Y} } );        
                    }
                } else if( a > R[i].rd.X ) {
                    if(b < R[i].ld.Y) {
                    } else if(b > R[i].lu.Y) {
                    } else {}
                } else {
                    if(b < R[i].ld.Y) {
                        flag = 1;
                        Q.push( { hypot(R[i].ld.X - a, R[i].ld.Y - b) + path, {R[i].ld.X, R[i].ld.Y} } );        
                        Q.push( { hypot(R[i].rd.X - a, R[i].rd.Y - b) + path, {R[i].rd.X, R[i].rd.Y} } );        
                    } else if(b > R[i].lu.Y) {
                        flag = 1;
                        Q.push( { hypot(R[i].lu.X - a, R[i].lu.Y - b) + path, {R[i].lu.X, R[i].lu.Y} } );        
                        Q.push( { hypot(R[i].ru.X - a, R[i].ru.Y - b) + path, {R[i].ru.X, R[i].ru.Y} } );        
                    } else {}
                }
                if(flag) break;
            }
        }
        // --
        if(!flag) {
            ans = min(ans, path + hypot(x - a, y - b));
        }
    }
    //
    printf("%.3lf", ans);
}