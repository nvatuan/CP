#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    //--
    vector< queue<int> > vq (N+1, queue<int>() );
    for(int i = 1; i <= N; i++) {
        int tmp, nn = N-1;
        while(nn--) {
            cin >> tmp;
            vq[i].push(tmp);
        }
    }
    // -- draw borders
    // cout << "border";
    vq[0].push(-1);
    for(int i = 1; i <= N; i++) {
        vq[i].push(0);
    }
    // cout << "border end\n";
    // --
    int days = 0;
    int matches = N*(N-1)/2;
    int empty_day = 0;

    vector<int> today (N+1, 0);

    while( matches ) {
        empty_day = 1;
        days++;
        //
        for(int i = 1; i <= N; i++) {
            int against = vq[i].front();
            // cout << "matching players: " << i << " vs " << against << endl;
            // cout << "check opponent: " << against << " vs " << vq[against].front() << endl;
            if( (vq[against].front() == i) && (today[i] != days) && (today[against] != days) ) {
                empty_day = 0;
                matches--;

                vq[i].pop();
                vq[against].pop();

                today[i]        = days;
                today[against]  = days;
            }
        }
        //
        if(empty_day) {
            cout << -1;
            return 0;
        }
    }
    cout << days;
    return 0;
}