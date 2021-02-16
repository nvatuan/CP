#include <bits/stdc++.h>
using namespace std;

int N;
string S;

vector< pair<int, int> > P;
vector< int > choosen;
#define X first
#define Y second

double ans = 10001.0;

double dist(int i, int j) {
    int dx = P[i].X - P[j].X;
    int dy = P[i].Y - P[j].Y;
    return sqrt( dx*dx + dy*dy );
}

void Try(int pi, vector< int > choosen, double subAns) {
    if( subAns >= ans ) return;
    // --
    if( pi < N ) {
        int i = 0;
        for(i = 0; i < 2*N; i++) {
            if( !choosen[i] ) {
                choosen[i] = 1;
                break;
            }
        }
        // --
        for(int j = i+1; j < 2*N; j++) {
            if( !choosen[j] ) {
                choosen[j] = 1;
                Try(pi + 1, choosen, subAns + dist(i, j) );
                choosen[j] = 0;
            }
        }
    } else {
        if( ans > subAns ) ans = subAns;
    }
}

int main() {
    //freopen("test.txt", "r", stdin);
    //
    int t = 0;
    while(1) {
        scanf("%d", &N);
        if(!N)    break;
        t++;
        // --
        ans = 10001.0;

        P.resize(2*N);

        choosen.clear();
        choosen.resize(2*N, 0);

        for(int i = 0; i < 2*N; i++) {
            cin >> S;
            scanf("%d%d", &P[i].X, &P[i].Y);
        }
        // --
        //random_device rd;
        //mt19937 g(rd());
        //shuffle(P.begin(), P.end(), g);
        // --
        Try(0, choosen, 0.0);
        printf("Case %d: %.2lf\n", t, ans);
    }
}