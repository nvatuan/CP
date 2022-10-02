#include <bits/stdc++.h>

using namespace std;
vector<pair<long long, long long>> a;
vector<pair<long long, long long>> b;
vector<pair<long long, long long>> ans;
int n, m;
void solve()
{
  a.push_back({0, 1e15});
  b.push_back({0, 1e15});
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int x, y;
    cin >> x >> y;
    a.push_back({x, y});
  }
  cin >> m;
  for (int i = 1; i <= m; i++)
  {
    int x, y;
    cin >> x >> y;
    b.push_back({x, y});
  }
  bool mem = 0;
  while (a.size() > 0 && b.size() > 0)
  {
    auto A = a.back();
    a.pop_back();
    auto B = b.back();
    b.pop_back();
    long long _min = min(A.second, B.second);
    if (mem)
    {
      if (A.first + B.first + mem >= 10)
      {
        ans.push_back({(A.first + B.first + mem) % 10, _min});
        mem = 1;
      }
      else
      {
        ans.push_back({A.first + B.first + mem, 1});
        mem = 0;
        _min = 1;
      }
    }
    else
    {
      if (A.first + B.first >= 10)
      {
        ans.push_back({(A.first + B.first) % 10, 1});
        mem = 1;
        _min = 1;
      }
      else
      {
        ans.push_back({A.first + B.first, _min});
        mem = 0;
      }
    }
    A.second -= _min;
    B.second -= _min;
    if (A.second > 0)
    {
      a.push_back(A);
    }
    if (B.second > 0)
    {
      b.push_back(B);
    }
  }
  vector<pair<long long, long long>> res;
  while (ans.size() > 0 && ans.back().first == 0)
  {
    ans.pop_back();
  }
  reverse(ans.begin(), ans.end());
  for (auto &i : ans)
  {
    if (i.second == 0)
    {
      continue;
    }
    if (res.size() == 0)
    {
      res.push_back(i);
      continue;
    }
    if (i.first == res.back().first)
    {
      res.back().second += i.second;
      continue;
    }
    res.push_back(i);
  }
  cout << res.size() << endl;
  for (auto &i : res)
  {
    cout << i.first << ' ' << i.second << endl;
  }
}
int main()
{
  // freopen("data.inp", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
