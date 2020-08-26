#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

int main() {
    cin >> n >> k;
    cin >> s;
    // -- 
    vector< pair<char, int> > seg;
    for(int i = 0; i < n; i++) {
        if( i == 0 || (s[i] != seg.rbegin()->first) ) {
            seg.push_back( {s[i], 0} );
        }
        (seg.rbegin()->second)++;
    }
    // --
    int currentHappy = 0;
    for(auto &p : seg) {
        currentHappy += (p.second-1);
    }
    // --
    int d = (seg.size() - 1) / 2;
    currentHappy += (min(d, k) * 2);
    currentHappy += ((k > d) && !(seg.size() & 1));
    //
    cout << currentHappy;
}