#include <bits/stdc++.h>
using namespace std;

const int DEBUG = 1;

double n, p1, p2, v1, v2;

void solve() {
    cin >> n >> p1 >> v1 >> p2 >> v2;

    if (p1 > p2) {
        swap(p1, p2);
        swap(v1, v2);
    }

    // 1 man walks all the way
    double ans_t1man = min(
        { (n+p1)/v1, (n+n-p2)/v1, (n+p1)/v2, (n+n-p2)/v2 }
    );
    if(DEBUG) cerr << "1 Man:";
    if(DEBUG) cerr << ans_t1man << endl;
    // -> <-
    double t_meet = (p2-p1) / (v1+v2);
    double ans_tagainst = t_meet * 2 + max(p1/v1, (n-p2)/v2);
    if(DEBUG) cerr << "2 Against:";
    if(DEBUG) cerr << ans_t1man << endl;

    // <- ->
    double ans_tsep = (p1 + n + n - p2) / (v1 + v2);
    if(DEBUG) cerr << "2 sep:";
    if(DEBUG) cerr << ans_tsep << endl;

    // <- <- or -> ->
    double t_meet_same = (p1 + p2) / (v1 + v2);
    double ans_meet_same = t_meet_same * 2 + (n-p2)/v2;
    if(DEBUG) cerr << "2 left:";
    if(DEBUG) cerr << ans_meet_same << endl;

    double t_meet_same_2 = (n+n-p2 - p1)/(v1+v2);
    double ans_meet_same_2 = t_meet_same_2 * 2 + p1/v1;
    if(DEBUG) cerr << "2 right:";
    if(DEBUG) cerr << ans_meet_same_2 << endl;
    cout << min({ans_t1man, ans_tagainst, ans_tsep, ans_meet_same, ans_meet_same_2}) << '\n';
}

int main() {
    if(DEBUG) cerr << setprecision(9) << fixed;
    cout << setprecision(9) << fixed;
    int T; cin >> T;
    while (T--)
        solve();
}