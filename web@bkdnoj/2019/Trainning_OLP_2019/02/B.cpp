#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main() {
    cin >> n >> m >> k;
    //
    vector<vector<int>> B (n + 1, vector<int> (m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            B[i][j] = (c - 'a' + 1);
        }
    }
    // --
    vector<vector<int>> prefix (n+1, vector<int> (m+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
            if( B[i][j] == 1 ) prefix[i][j]++;
        }
    }
    // --
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            for(int r = i+1; r <= n; r++) {
                if( !(B[r][j]^B[i][j]) ) 
                    for(int rj = j+1; rj <= m; rj++) {
                        if( !(B[i][j]^B[i][rj]) && !(B[i][rj]^B[r][j]) && !(B[r][rj]^B[i][j]) ) {
                            //printf("(%d, %d) == (%d, %d) == (%d, %d) == (%d, %d)\n", i, j, i, rj, r, j, r, rj);
                            ans += ( (prefix[r][rj] - prefix[r][j-1] - prefix[i-1][rj] + prefix[i-1][j-1]) <= k );
                        }
                        if( (prefix[r][rj] - prefix[r][j-1] - prefix[i-1][rj] + prefix[i-1][j-1]) > k ) break;
                    } 
                
            }

        }
    }
    //
    cout << ans;
}