#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

int n, m;
llong mat[200][200];
int odd[200][200];

llong get(int a, int b, int x, int y) {
    return mat[x][y] - mat[x][b-1] - mat[a-1][y] + mat[a-1][b-1];
}
int get2(int a, int b, int x, int y) {
    return odd[x][y] - odd[x][b-1] - odd[a-1][y] + odd[a-1][b-1];
}
const llong INF = (1000000001LL);
const llong INFLL = INF*1000000000LL;

void solve() {
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf("%lld", &mat[i][j]);
            odd[i][j] = (mat[i][j] & 1LL);
            mat[i][j] += (mat[i-1][j] - mat[i-1][j-1] + mat[i][j-1]);
            odd[i][j] += (odd[i-1][j] - odd[i-1][j-1] + odd[i][j-1]);
        }
    }
    //while (true) {
    //    int a,b,c,d;
    //    cin >> a>>b>>c>>d;
    //    cout << get(a,b,c,d)<<endl;
    //}
    //for (int i=0; i<=n; i++, cout <<'\n')
    //    for (int j=0; j<=m; j++) {
    //        cout << mat[i][j] << ' ';
    //    }

    llong ans = -INFLL;
    
    for (int i=1; i<=m; i++) {
        for (int j=i; j<=m; j++) {
            llong currMax = -INFLL;
            llong totalMax = -INFLL;
            for (int c=1; c<=n; c++) {
                int odds = get2(c, i, c, j);
                if (odds > 0) {
                    currMax = -INFLL;
                    continue;
                }
                llong temp = get(c, i, c, j);
                currMax = max(currMax, 0LL) + temp;
                totalMax = max(totalMax, currMax);
            }
            ans = max(ans, totalMax);
        }
    }
    if (ans <= 0) printf("impossible\n");
    else printf("%lld\n", ans);
}


int main() {
    int t;
    cin >> t;
    for (int it=1; it<=t; it++) {
        printf("Test %d: ", it);
        solve();
    }
}