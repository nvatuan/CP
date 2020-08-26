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


int n,m;
char a[1005][1005], ch[1005][1005];

bool can(int x, int y){
    int co=0;
    foru(i,x-1,x+1) foru(j,y-1,y+1) if(a[i][j]=='#') co++;
    if(a[x][y]=='#') co--;
  //  cout<<co<<endl;
    if(co==8) return 1;
    return 0;
}

void fil(int x, int y){
    char bo=ch[x][y];

    foru(i,x-1,x+1) foru(j,y-1,y+1) ch[i][j]='#';
    ch[x][y]=bo;
}

ll solve(){
    cin>>n>>m;
    foru(i,1,n) foru(j,1,m) cin>>a[i][j], ch[i][j]='.';

    foru(i,2,n-1) foru(j,2,m-1){
       // cout<<i<<" "<<j<<endl;
        if(can(i,j)){
            fil(i,j);
        }
    }


    foru(i,1,n){
        foru(j,1,m) if(ch[i][j]!=a[i][j]){
            cout<<"NO";
            return 0;
        }
    }

    cout<<"YES";
}

int main()
{
    ios::sync_with_stdio(0);

   // freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    solve();
    return 0;
}