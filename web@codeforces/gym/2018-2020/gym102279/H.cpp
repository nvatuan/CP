#include <bits/stdc++.h>
using namespace std;

int n;

bool check(vector<int> P, vector< vector<int> > D) {
    for(int flip = 0; flip < (1<<n); flip++) {
        int ends = -1;
        int j = 0;
        for(int &i : P) {
            if( (ends == -1) || (ends == D[i][((flip >> j) & 1)] ) ) {
                ends = D[i][!((flip>>j) & 1)];
                j++;
            } else break;
        }
        //
        if( j == n ) {
            for(int i = 0; i < n; i++) {
                cout << P[i]+1 << ' ' << "ab"[(flip >> i) & 1] << '\n';
            }
            return true;
        }
    }
    //
    return false;
}

int main(){
    cin >> n;
    vector< vector<int> > domino (n, vector<int>(2, 0) );
    for(int i = 0; i < n; i++) {
        cin >> domino[i][0] >> domino[i][1];
    }
    //
    vector< int > P (n, 0);
    for(int i = 0; i < n; i++) P[i] = i;
    //
    do {
        if(check(P, domino)) return 0;
    } while ( next_permutation(P.begin(), P.end()) );
    //--
    assert(0);
}