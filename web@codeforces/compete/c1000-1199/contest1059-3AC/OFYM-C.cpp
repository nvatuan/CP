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

vector<int> ans;
int tmp;

void tinh(int n){
    if(n==3){
        ans.pb(tmp);
        ans.pb(tmp);
        ans.pb(tmp*3);
        return ;
    }

    if(n==2){
        ans.pb(tmp);
        ans.pb(tmp*2);
        return ;
    }

    if(n==1){
        ans.pb(tmp);
        return ;
    }

    for(int i=1;i<=n;i+=2){
        ans.pb(tmp);
    }
    tmp*=2;
    tinh(n/2);
}

int n;
ll solve(){
    cin>>n;

    tmp = 1;
    tinh(n);

    for(int x:ans) cout<<x<<" ";
}

int main()
{
    ios::sync_with_stdio(0);

   // freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    solve();
    return 0;
}