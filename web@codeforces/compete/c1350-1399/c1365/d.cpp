#include <bits/stdc++.h>
using namespace std;

const int __multitest = 1;
const int __debugmode = 0;

template<typename T>
T In() { T x; cin >> x; return x; }

// --
int n, m;
vector<vector<int>> matrix;
#define EMPTY 0
#define WALL 1
#define GOOD 2
#define BAD 3

vector<vector<int>> visited;
bool dfs(int i, int j) {
    if (i < 0 or i == n) return false;
    if (j < 0 or j == m) return false;
    if (matrix[i][j] == WALL) return false;
    if (visited[i][j]) return false;
    if (i == n-1 and j == m-1) return true;
    //
    visited[i][j] = true;
    bool flag = false;
    for (int d = -1; d <= 1; d += 2) {
        flag |= dfs(i + d, j);
        flag |= dfs(i, j + d);
    }
    return flag;
}

void solve() {
    cin >> n >> m;
    matrix = vector<vector<int>> (n, vector<int> (m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            switch (c) {
                case '.':
                    matrix[i][j] = EMPTY;
                    break;
                case '#':
                    matrix[i][j] = WALL;
                    break;
                case 'G':
                    matrix[i][j] = GOOD;
                    break;
                case 'B':
                    matrix[i][j] = BAD;
                    break;
            }
        }
    // ==
    bool possible = (matrix[n-1][m-1] != BAD);
    auto surround = [&](int x, int y) -> void {
        for (int d = -1; d <= 1; d += 2) {
            if (x + d < 0 or x + d == n) continue;
            if (matrix[x + d][y] == EMPTY) matrix[x + d][y] = WALL;
            if (matrix[x + d][y] == GOOD) possible = false;
        }
        for (int d = -1; d <= 1; d += 2) {
            if (y + d < 0 or y + d == m) continue;
            if (matrix[x][y + d] == EMPTY) matrix[x][y + d] = WALL;
            if (matrix[x][y + d] == GOOD) possible = false;
        }
    };
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == BAD) surround(i, j);
    
    // cout << "MAP\n";
    // for (int i = 0; i < n; i++) {
        // for (int j = 0; j < m; j++) {
            // cout << matrix[i][j];
        // }
        // cout << endl;
    // }
        
    if (not possible)  {
        cout << "No" << endl;
        return;
    }
    // ==
    int good_people = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            good_people += (matrix[i][j] == GOOD);

    queue< pair<int, int> > q;
    visited = vector<vector<int>> (n, vector<int>(m, 0));
    q.push( {n-1, m-1} );

    while( not q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //
        if (x < 0 or x == n) continue;
        if (y < 0 or y == m) continue;
        if (matrix[x][y] == WALL) continue;
        if (visited[x][y]) continue;
        visited[x][y] = true;
        if (matrix[x][y] == GOOD) good_people--;
        //
        q.push({x - 1, y});
        q.push({x + 1, y});
        q.push({x, y - 1});
        q.push({x, y + 1});
    }

    if (good_people == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return;
}

int main() { 
    for (int t = (__multitest ? In<int>() : 1); t; t--) solve();
}