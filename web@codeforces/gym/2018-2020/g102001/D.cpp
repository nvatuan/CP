#include <bits/stdc++.h>
using namespace std;
#define task "data"

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FOD(i, a, b) for (int i = a; i >= b; --i)
#define FRSZ(i, a) for (int i = 0; i < a.size(); ++i)
#define FDSZ(i, a) for (int i = a.size() - 1; i >= 0; --i)
#define debug(x) cout << #x << " = " << x << endl;
#define debugarr(x, n)       \
    {                        \
        FOR(_, 1, n)         \
        cout << x[_] << " "; \
        cout << endl;        \
    }
#define debugvi(x)           \
    {                        \
        FRSZ(_, x)           \
        cout << x[_] << " "; \
        cout << endl;        \
    }
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

int n, m;
string a[501];
int main()
{
    // freopen("data.inp", "r", stdin);
    // freopen("data.out", "w", stdout);
    cin >> n >> m;
    string s;
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, a[i]);
    }
    int cnt = 0;

    if (n == 2 && m == 2)
    {
        cout << 0;
        return 0;
    }
    if (n == 2)
    {
        int ans = 0;

        for (int j = 1; j < m - 1; j++)
        {
            if (a[0][j] == '.' && a[n - 1][j] == '.')
                ans++;
        }
        cout << ans;
        return 0;
    }
    if (m == 2)
    {
        int ans = 0;

        for (int j = 1; j < n - 1; j++)
        {
            if (a[j][0] == '.' && a[j][m - 1] == '.')
                ans++;
        }

        cout << ans;
        return 0;
    }
    // --- both side is larger than 2




    cout << cnt << endl;
    return 0;
}