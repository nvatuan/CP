#include <bits/stdc++.h>

#define base 1000000007LL
#define ll long long
#define ld long double
#define X first
#define Y second
#define pb push_back
#define EPS 1e-15
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())

#define ms(s, n) memset(s, n, sizeof(s))

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORE(i,a,b) for (int i = (a); i >= (b); i--)
#define sqr(a) (a)*(a)

#define foru(i,a,b) for (ll i = (a); i <= (b); ++i)
#define ford(i,a,b) for (ll i = (a); i >= (b); --i)
#define cbit(a) __builtin_popcount(a)
#define uni(a) (a).resize(unique(all(a)) - (a).begin())

#define FORALL(it, a) for (__typeof((a).begin()) it = (a).begin(); it !=(a).end(); it++)
using namespace std;
typedef pair<ll, ll> II;
typedef pair<int, int> ii;


const int M=2e5+7;
const int MM=4*M;
const ll MOD=1e9+7;
const int oo=1e9;
const ll MAX=1e18;

ll n,L,a,t[M],l[M],ans;

ll solve(){
    cin>>n>>L>>a;
    foru(i,1,n){
        cin>>t[i]>>l[i];
    }
    t[n+1]=L;
    foru(i,0,n){
        ans += (t[i+1]-(t[i]+l[i]-1)-1)/a;
    }

    cout<<ans;
}

int main()
{
    ios::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    solve();
    return 0;
}