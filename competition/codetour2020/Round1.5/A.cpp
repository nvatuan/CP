#include <bits/stdc++.h>
using namespace std;

int n;
int k;
pair<int, int> nam[100050], nu[100050];

int main() {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        double d = stod(s);
        nam[i].first = (int)((d+0.0001)*10);
        nam[i].second = i+1;
    }
    map<pair<int, int>, string> correctFormat;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        double d = stod(s);
        nu[i].first = (int)((d+0.0001)*10);
        nu[i].second = i+1;
        correctFormat[nu[i]] = s;
    }

    sort(nam, nam+n);
    sort(nu, nu+n, [&](pair<int, int> pa, pair<int, int> pb) -> bool {
        int da = pa.first;
        int db = pb.first;
        if (da == db) return pa.second < pb.second;
        return da > db;
    });

    // for (int i=0; i<n; i++) {
    //     cout << nam[i].first << ' ' << nam[i].second << endl;
    // }
    // for (int i=0; i<n; i++) {
    //     cout << nu[i].first << ' ' << nu[i].second << endl;
    // }

    int rk = -1;
    for (int i=0; i<n; i++) {
        if (nam[i].second == k) rk = i;
    }
    cout << nu[rk].second << ' ' << correctFormat[nu[rk]] << endl; 
}