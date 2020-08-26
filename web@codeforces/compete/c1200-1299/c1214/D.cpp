#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > Map;
int n, m;

int lowerPathSize;
pair<int,int> lowerPath[2000001];

vector< vector<int> > mark1;
int dfs_lowerPrior(int depth, int x, int y) {
    if(Map[x][y]) return 0;

    if(mark1[x][y]) return 0;
    mark1[x][y] = 1;

    if(x == n && y == m) {
        lowerPathSize = depth;
        return 1;
    }

    lowerPath[depth] = make_pair(x, y);
    if( dfs_lowerPrior(depth+1, x+1, y) ) return 1;
    if( dfs_lowerPrior(depth+1, x, y+1) ) return 1;
    return 0;
}

int upperPathSize;
pair<int,int> upperPath[2000001];

vector< vector<int> > mark2;
int dfs_upperPrior(int depth, int x, int y) {
    if(Map[x][y]) return 0;

    if(mark2[x][y]) return 0;
    mark2[x][y] = 1;

    if(x == n && y == m) {
        upperPathSize = depth;
        return 1;
    }

    upperPath[depth] = make_pair(x, y);
    if( dfs_upperPrior(depth+1, x, y+1) ) return 1;
    if( dfs_upperPrior(depth+1, x+1, y) ) return 1;
    return 0;
}

int crossPath(){
    //set< pair<int,int> > CellOnPath;
    vector< vector<int> > mark ( n+2, vector<int> (m+2, 0) );
    
    for(int i = 1; i < lowerPathSize; i++) {
        //CellOnPath.insert( lowerPath[i] );
        mark[ lowerPath[i].first ][ lowerPath[i].second ] = 1;
    }
    for(int i = 1; i < upperPathSize; i++) {
        //if( CellOnPath.find(upperPath[i]) != CellOnPath.end() ) return 1;
        if( mark[ upperPath[i].first ][ upperPath[i].second ] ) return 1;
    }
    return 0;
}

int main(){
    cin >> n >> m;
    Map     = vector< vector<int> >( n+2, vector<int> (m+2, 1) );
    mark1   = vector< vector<int> >( n+2, vector<int> (m+2, 0) );
    mark2   = vector< vector<int> >( n+2, vector<int> (m+2, 0) );

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c;
            do {
                scanf("%c", &c);
            } while( c != '#' && c != '.' );
            Map[i][j] = (c == '#');
        }
    }
    // --
    if( dfs_upperPrior(0, 1, 1) && dfs_lowerPrior(0, 1, 1) ) {
        if(crossPath()) cout << 1;
        else cout << 2;
    } else {
        cout << 0;
    }
    //
    // cout << "\nUpper path is: ";
    // for(int i = 0; i < upperPathSize; i++) {
    //     cout << "(" << upperPath[i].first << ", " << upperPath[i].second << ") -> ";
    // }

    // cout << "\nLower path is: ";
    // for(int i = 0; i < lowerPathSize; i++) {
    //     cout << "(" << lowerPath[i].first << ", " << lowerPath[i].second << ") -> ";
    // }
}