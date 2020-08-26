#include <bits/stdc++.h>
using namespace std;

int N, M;
bitset<1000> B;

vector< bitset<1000> > switches;
vector< unordered_set< bitset<1000> > > hashes;

int L;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //
    cin >> N >> M;
    cin >> L;
    for(int ip; L; L--) {
        cin >> ip;
        B.flip(ip-1);
    }
    // --
    switches.resize( N, bitset<1000>() );
    hashes.resize(N, unordered_set<bitset<1000>>() );
    // --
    for(int i = 0; i < N; i++) {
        cin >> L;
        for(int ip; L; L--) {
            cin >> ip;
            switches[i].flip(ip-1);
        }
    }
    // --
    int ans = 0;
    int current_switch = 0;
    for(int in = 2*N; in >= 0; in--) {
        if(B.count() == 0) {
            cout << ans;
            return 0;
        }
        //
        if( hashes[current_switch].find(B) == hashes[current_switch].end() ) {
            hashes[current_switch].insert(B);
        } else {
            cout << -1;
            return 0;
        }
        //
        B ^= switches[current_switch];
        ans++;
        current_switch = ((current_switch + 1) % N);
    }
    //
    cout << -1;
    return 0;
}