#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, a, b, c;
    cin >> N >> a >> b >> c;
    N++;
    // --
    vector<int> state(N, 0);
    state[0] = -1;
    //
    int dice = 0;
    int na = 0, nb = 0, nc = 0;
    //
    for(int i = 0; i < 10*N; i++) {
        na += a;
        na %= N;
        dice++;
        //cerr << "na = " << na << endl;
        if( state[na] == 0 ) state[na] = 1;
        if( na != 0 && state[na] != 1 ) {cout << dice; return 0;}
        //
        nb += b;
        nb %= N;
        dice++;
        //cerr << "nb = " << nb << endl;
        if( state[nb] == 0 ) state[nb] = 2;
        if( nb != 0 && state[nb] != 2 ) {cout << dice; return 0;}
        //
        nc += c;
        nc %= N;
        dice++;
        //cerr << "nc = " << nc << endl;
        if( state[nc] == 0 ) state[nc] = 3;
        if( nc != 0 && state[nc] != 3 ) {cout << dice; return 0;}
    }
    cout << 3000000000;
    //cerr << "\ndice = " << dice;
    return 0;
}