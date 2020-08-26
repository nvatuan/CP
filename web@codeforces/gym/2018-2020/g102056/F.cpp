#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(ll i = (a); i<= (b); ++i)
#define L first
#define R second

using namespace std;

const int M=2e5+5;
const ll INF = 1e18;
typedef pair<int, int> ii;
typedef pair<ll, int> II;

bool cmp(double x, double y) {
    if(abs(x-y) < 1e-15) return 1;
    return 0;
}
struct Point{
    double x,y,z;
    Point(){}
    Point(double x, double y, double z): x(x), y(y), z(z) {}
    double abs() {
        return sqrt(x*x+y*y+z*z);
    }

    Point operator - (Point o) {
        Point res;
        res.x = x-o.x;
        res.y = y-o.y;
        res.z = z-o.z;
        return res;
    }
};

bool cmp(Point a, Point b) {
    return (cmp(a.x,b.x) && cmp(a.y,b.y) && cmp(a.z,b.z));
}

double area(double a, double b, double c) {
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

const double PI=acos(-1);
void solve() {
    Point s,t,o;
    double r;
    cin>>o.x>>o.y>>o.z>>r;
    cin>>s.x>>s.y>>s.z>>t.x>>t.y>>t.z;

    if(cmp(s,t)) {
        cout<<0.0<<"\n";
        return ;
    }
    Point pso = o-s;
    double so = pso.abs();
    Point pot = t-o;
    double ot = pot.abs();
    Point pst = s-t;
    double st = pst.abs();
    Point pos = s-o;
    double cost = (pos.x*pot.x+pos.y*pot.y+pos.z*pot.z)/(pos.abs()*pot.abs());

    double coss = (pss.x*pst.x+pss.y*pst.y+pss.z*pst.z)/(pss.abs()*pst.abs());

    double goctam = acos(cost);

    if(goctam*2+1e-15 < PI) {
        cout<<st<<"\n";
        return ;
    }
    double oh = area(so,ot,st)*2/st;


    if(oh - 1e-15 >= r) {
        cout<<st<<"\n";
        return ;
    }

    double sh = sqrt(so*so-oh*oh);
    double ht = st-sh;

    double si = sqrt(so*so - r*r);
    double tj = sqrt(ot*ot - r*r);
    //cout<<oh<<" - "<<ot<<endl;
    double sot = acos(oh/so) + acos(oh/ot);
    double soi = acos(r/so) + acos(r/ot);
    double ioj = sot-soi;

    double ij = r*ioj;
    //cout<<si<<" "<<sot<<" "<<tj<<endl;
    cout<<si+tj+ij<<"\n";
}

int main() {
    ios::sync_with_stdio(0);
   // freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    cout<<fixed<<setprecision(6);
    while(t--) solve();
}