#include <bits/stdc++.h>
using namespace std;

int H, W;
vector< vector<bool> > Wall;

int bfs(int sx, int sy){
    vector< vector<bool> > Vis (H+2, vector<bool> (W+2, 0));
    queue< pair<int, pair<int, int> > > Q;

    Q.push( {0, {sx, sy}} );
    // ------------------------------------
    int subMaxMoves = 0;
    while(!Q.empty()) {
        pair<int, int> coor = Q.front().second;
        int            step = Q.front().first;
        Q.pop();
        // --
        if( Vis[coor.first][coor.second] ) continue;
        Vis[coor.first][coor.second] = 1;
        //
        subMaxMoves         = max(subMaxMoves, step);
        // --
        for(int d = -1; d <= 1; d += 2) {
            if(!Wall[coor.first + d][coor.second]) {
                Q.push( {step+1, {coor.first+d, coor.second}} );
            }
            if(!Wall[coor.first][coor.second + d]) {
                Q.push( {step+1, {coor.first, coor.second+d}} );
            }
        }
    }
    //
    return subMaxMoves;
}

int main() {
    cin >> H >> W;
    Wall.resize(H+2, vector<bool> (W+2, 1));
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            char c;
            cin >> c;
            Wall[i][j] = (c == '#');
        }
    }
    // --------------------------------------------
    int maxMoves = 0;
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            if(!Wall[i][j]) maxMoves = max(maxMoves, bfs(i, j));
        }
    }
    //
    cout << maxMoves << endl;
    return 0;
}