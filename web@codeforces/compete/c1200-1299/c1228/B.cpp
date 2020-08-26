#include <bits/stdc++.h>
using namespace std;

int h, w;
int r[10000];
int c[10000];
int grid[1001][1001];

#define W -1
#define B 1
#define _ 0

int construct() {
    // -- top down first
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < r[i]; j++) {
            grid[i][j] = B;
        }
        if(r[i] < w) grid[i][r[i]] = W;
    }
    // -- left right
    for(int i = 0; i < w; i++) {
        // c[i] -> grid[j][i]
        for(int j = 0; j < c[i]; j++) {
            if( grid[j][i] == _ || grid[j][i] == B ) grid[j][i] = B;
            else return false;
        }
        if(c[i] < h) {
            if( grid[c[i]][i] == _ || grid[c[i]][i] == W ) grid[c[i]][i] = W;
            else return false;
        }
    }
    //
    return true;
}

long long counting() {
    const int M = 1000000007;
    long long result = 1;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++) 
            if( grid[i][j] == _ ) {
                result *= 2;
                result %= M;
            }
    return result;
}

int main () {
    cin >> h >> w;
    for(int i = 0; i < h; i++) cin >> r[i];
    for(int i = 0; i < w; i++) cin >> c[i];
    //--
    if( construct() ) {
        cout << counting();
    } else {
        cout << 0;
    }
}