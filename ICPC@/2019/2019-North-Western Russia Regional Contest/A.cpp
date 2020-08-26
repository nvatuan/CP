#include <bits/stdc++.h>
using namespace std;

int L, S, n;

int main() {
    cin >> S >> L >> n;
    int sS = 0, sL = 0;
    int move = 0;
    while( ((sS + S) < n or (sL + L) < n) ) {
        if(sS == sL) {
            sS = (sL + L - S);
        } else {
            sL += (L - S);
        }
        //cout << sS << " " << sL << endl;
        move++;
    }
    cout << move;
}