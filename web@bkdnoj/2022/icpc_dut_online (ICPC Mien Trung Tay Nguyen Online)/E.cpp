#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Scale
{
  ll p, q, x, y;
  Scale() {}
  Scale(ll a, ll b, ll c, ll d) : p(a), q(b), x(c), y(d) {}

  ll l, r;
  ll total;
  int solved = 0;

  void read()
  {
    cin >> p >> q >> x >> y;
  }

  void print()
  {
    cout << p << ' ' << q << ' ' << x << ' ' << y << endl;
    // cout << "tl=" << tl << ' ';
    // cout << "ml=" << ml << endl;
    // cout << "tr=" << tr << ' ';
    // cout << "mr=" << mr << endl;
    cout << "total=" << total << endl;
  }
};

int n;
Scale scs[5000];
int done = 1;

void solve(Scale &sc)
{
  if (sc.solved)
    return;

  if (sc.x == 0 and sc.y == 0)
  {
    sc.l = sc.r = 1;
  }
  else if (sc.x == 0)
  { // one side 0
    sc.l = 1;
    solve(scs[sc.y]);
    sc.r = scs[sc.y].total;
  }
  else if (sc.y == 0)
  { // one side 0
    sc.r = 1;
    solve(scs[sc.x]);
    sc.l = scs[sc.x].total;
  }
  else
  { // two scale
    solve(scs[sc.x]);
    solve(scs[sc.y]);
    sc.l = scs[sc.x].total;
    sc.r = scs[sc.y].total;
  }

  long long t, m;
  t = sc.r * sc.q;
  m = sc.l * sc.p;
  ll g = __gcd(m, t);
  m /= g;
  t /= g;
  sc.l *= t;
  sc.r *= m;
  sc.total = sc.l + sc.r;
  sc.solved = done++;
}

int main()
{
  // freopen("data.inp", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    scs[i].read();
  }

  for (int i = 1; i <= n; i++)
  {
    solve(scs[i]);
  }

  int root = 1;
  for (int i = 1; i <= n; i++)
  {
    if (scs[root].solved <= scs[i].solved)
    {
      root = i;
    }
  }
  cout << scs[root].total << '\n';
}
