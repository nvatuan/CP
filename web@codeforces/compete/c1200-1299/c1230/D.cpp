#include <bits/stdc++.h>
using namespace std;

int N;

#define algo first
#define skill second

int main(){
    cin >> N;
    vector< pair<unsigned long long, int> > students (N, pair<unsigned long long, int>() );
    unsigned long long a;
    for(int i = 0; i < N; i++) {
        cin >> a;
        students[i].algo = a;
    }
    for(int b, i = 0; i < N; i++) {
        cin >> b;
        students[i].skill = b;
    }

    long long ans = 0;

    if(N > 1) {
        sort(students.begin(), students.end());
        //
        unordered_map< unsigned long long, int > multiple;
        set< unsigned long long > noConflict;

        for( int i = N-1; i > -1; --i ) {
            if( i > 0 && students[i].algo == students[i-1].algo ) {
                multiple[students[i].algo] = 1;
                noConflict.insert(students[i].algo);
            }
            if(multiple[students[i].algo]) ans += students[i].skill;
        }
        //
        sort(students.begin(), students.end(), [](pair<unsigned long long, int> a, pair<unsigned long long, int> b) { return a.skill > b.skill; } );
        // for(auto &p : students) {
        //     cout << p.first << ' ';
        // }
        // cout << endl;
        // for(auto &p : students) {
        //     cout << p.second << ' ';
        // }
        //cout << endl;
        //
        for(int i = 0; i < N; i++) {
            if( !multiple[students[i].algo] ) {
                unsigned long long AL = students[i].algo;
                for(auto &al : noConflict) AL = (AL & (~al));
                //
                if(!AL) {
                    ans += students[i].skill;
                    noConflict.insert(students[i].algo);
                }
            }
        }
    }
    //
    cout << ans;
}