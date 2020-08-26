#include <bits/stdc++.h>
using namespace std;

int n, d, e;
int maxd, maxe;

int min_after = INT_MAX;

int main() {
    cin >> n;
    cin >> d;
    cin >> e;
    //
    maxd = (n/d);
    for(int dollar = 0; dollar <= maxd; dollar++) {
        min_after = min(min_after, (n - (dollar*d)) % (5*e));
        //cout << dollar << ' ' << min_after << endl;
    }
    cout << min_after;
}