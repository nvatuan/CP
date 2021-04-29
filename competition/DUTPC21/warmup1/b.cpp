#include <bits/stdc++.h>
using namespace std;

int g[5][5];

int check(int x, int y) {
    int m[2] = {};

    m[g[x][y]]++;
    m[g[x+1][y]]++; 
    m[g[x][y+1]]++;
    m[g[x+1][y+1]]++;

    return ((m[0] == 4) || (m[1] == 4));
}

int main() {
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++) {
            char c; cin >> c;
            if (c=='#') g[i][j] = 1;
        }
    
    int poss=0;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            poss |= check(i, j);
        }
    }

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++) {
            g[i][j] ^= 1;
            for (int i=0; i<3; i++) {
                for (int j=0; j<3; j++) {
                    poss |= check(i, j);
                }
            }
            g[i][j] ^= 1;
        }
    
    cout << (poss ? "YES" : "NO") << endl;
}