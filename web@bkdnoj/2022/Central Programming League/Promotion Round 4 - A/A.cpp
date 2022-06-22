#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int A, B, C, K;
string strat;

void solve() {
  cin >> A >> B >> C >> K;
  strat = "";
  if (B < K) {
    strat = "sheep_loop";
  }
  else
  if (B == K) {
    if (A + C <= K) strat = "sheep_both";
    else {
      if (A+C <= 2*K) strat = "sheep_partial_sheep_both";
    }
  }
  else {
    if (A + C < K) strat = "both_loop";
    else
    if (B <= 2*K and A + C == K) strat = "both_sheep";
  }
  int tmp;
  if (strat == "") cout << 0 << '\n';
  else {
    cout << "1\n";
    if (strat == "sheep_loop") {
      tmp = K-B;
      while (A + C > 0) {
        if (A) {
          printf("%d %d %d\n", min(tmp, A), B, 0);
          A -= min(tmp, A);
        }
        else {
          printf("%d %d %d\n", 0, B, min(tmp, C));
          C -= min(tmp, C);
        }
        if (A+C)
          printf("%d %d %d\n", 0, B, 0);
      }
    } else
    if (strat == "sheep_both") {
      printf("%d %d %d\n", 0, B, 0);
      printf("%d %d %d\n", 0, 0, 0);
      printf("%d %d %d\n", A, 0, C);
    }
    else
    if (strat ==  "sheep_partial_sheep_both") {
      printf("%d %d %d\n", 0, B, 0);
      printf("%d %d %d\n", 0, 0, 0);
      tmp = (A+C)-K;
      assert(tmp >= 0);
      if (A > C) {
        printf("%d %d %d\n", A-tmp, 0, C);
        A = tmp; C = 0;
      } else {
        printf("%d %d %d\n", A, 0, C-tmp);
        C = tmp; A = 0;
      }
      printf("%d %d %d\n", 0, B, 0);
      if (A) printf("%d %d %d\n", A, 0, 0);
      else
      if (C) printf("%d %d %d\n", 0, 0, C);
      printf("%d %d %d\n", 0, 0, 0);
      printf("%d %d %d\n", 0, B, 0);
    } else
    if (strat == "both_loop") {
      tmp = K - (A+C);
      while (B) {
        printf("%d %d %d\n", A, min(tmp, B), C);
        B -= min(tmp, B);
        if (B) printf("%d %d %d\n", A, 0, C);
      }
    } else
    if (strat == "both_sheep") {
      printf("%d %d %d\n", A, 0, C);
      printf("%d %d %d\n", 0, 0, 0);

      printf("%d %d %d\n", 0, K, 0);
      B -= K;
      printf("%d %d %d\n", A, 0, C);
      printf("%d %d %d\n", 0, B, 0);
      printf("%d %d %d\n", 0, 0, 0);
      printf("%d %d %d\n", A, 0, C);
    }
    printf("%d %d %d\n", -1, -1, -1);
  }
}

int main() {
  int t; cin >> t;
  while (t--)
    solve();
}
