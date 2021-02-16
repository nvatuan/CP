#include <bits/stdc++.h>
using namespace std;

const long long MOD = (long long) 1e9 + 7;
const int N = 2010;
long long C[N][N];

void precomp() {
    for (int i=0; i<N; i++) C[i][0] = 1;
    for (int i=1; i<N; i++) {
        for (int j=1; j<=i; j++) {
            // 1
            // 1 1
            // 1 2 1 
            // 1 3 3 1
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            C[i][j] %= MOD;
        }
    }
}

long long Co(int K, int N) {
    return C[N][K];
}

int n, m, r;
class Snake {
public:
    int X, Y, B;
    Snake() {}
};

Snake snakes[N];
long long point_earned[N];
long long include_matrix[N][N];
long long target[N][N];

int main() {
    precomp();
    cin >> n >> m >> r;
    for (int i=0; i<n; i++) {
        cin >> snakes[i].X >> snakes[i].Y >> snakes[i].B;
    }
    for (int i=0; i<n; i++) {
        long long affect = 0;
        for (int j=0; j<n; j++) {
            if (abs(snakes[i].X - snakes[j].Y) + abs(snakes[i].Y - snakes[j].Y) <= r) affect += snakes[j].B;
        }
        point_earned[i] = affect;
    }

    // init sweepline start, end position     
    for (int i=0; i<n; i++) {
        int x = snakes[i].X;
        int y = snakes[i].Y;
        // +1
        for (int row=x-r; row <= x+r; row++)
            if (0 <= row and row < N) include_matrix[row][max(y-r, 0)]++;

        // -1
        for (int row=x-r; row <= x+r; row++)
            if (0 <= row and row < N) include_matrix[row][min(y+r+1, N)]--;
    }
    // do the sweep line for each row
    for (int row=0; row<N; row++) {
        long long count = 0;
        for (int col=0; col<N; col++) {
            count += include_matrix[row][col];
            include_matrix[row][col] = count;
        }
    }

    //for (int row=0; row<=4; row++) {
    //    for (int col=0; col<=4; col++) {
    //        cout << include_matrix[row][col] << ' ';
    //    }
    //    cout << endl;
    //}

    // 
    unordered_map<int, int> include_mat_map;
    for (int i=0; i<n; i++) {
        include_mat_map[i] = include_matrix[snakes[i].X][snakes[i].Y];
    }

    unordered_map<int, long long> ways;
    for (int i=0; i<n; i++) {
        int recs = include_mat_map[i];
        assert(n-recs >= 0);
        cout << i << endl;
        for (int c=1; c<=recs; c++) {
            ways[i] = (ways[i] + Co(c, recs) * Co(m-c, n-recs) % MOD) % MOD;
        }
    }
    for (int i=0; i<n; i++) {
        cout << i << ' ' << ways[i] << '\n';
    }
    
    // result
    auto sqr = [&](long long x) -> long long { return x*x };

    long long ans = 0;
    for (int i=0; i<n; i++) {
        ans = ans + (sqr(snakes[i].B) % MOD * ways[i] % MOD);
        ans = (ans >= MOD ? ans - MOD : ans);
    }

    // -- add 2 ai aj
    for (int i=0; i<n; i++) {
        target[snakes[i].X][snakes[i].Y] += 1;
    }
    for (int x=1; x<=N; x++) {
        for (int y=1; y<=N; y++) {
            target[x][y] = target[x-1][y] + target[x][y-1] - target[x-1][y-1];
        }
    }

    auto getsum = [&](int mx, int nx, int my, int ny) -> long long {
        if (mx < nx || my < ny) return 0;
        return target[mx][my] - target[nx][my] - target[mx][ny] + target[nx][ny];
    };

    for (int s1=0; s1<n; s1++) {
        for (int s2=s1+1; s2<n; s2++) {
            int minX = max(snakes[s1].X, snakes[s2].X) - r;
            int maxX = min(snakes[s1].X, snakes[s2].X) + r;
            int minY = max(snakes[s1].Y, snakes[s2].Y) - r;
            int maxY = min(snakes[s1].Y, snakes[s2].Y) + r;

            int recs_that_kill_both = getsum(maxX, minX, maxY, minY);

            
        }
    }


}