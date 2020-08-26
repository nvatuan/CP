#include <bits/stdc++.h>
using namespace std;

int T, N;
int con[101][101];

int vist[101];

int dfs(int X, int Y, int throughX = 0, int current = 0, int dom = 1) {
    vist[current] = 1;

    if(current == X) throughX = 1;
    if(current == Y) {
        if(throughX) {
            dom = 1;
        } else {
            dom = 0;
        }
        return dom;
    }

    for(int v = 0; v < N; v++) {
        if( con[current][v] ) {
            if(dom) dom = dfs(X, Y, throughX, v);
        }
    }

    vist[current] = 0;
    return dom;
}

int main() {
    for(cin >> T; T; T--) {
        cin >> N;
        for(int i = 0; i < N; i++) 
            for(int j = 0; j < N; j++)
                cin >> con[i][j];
        //
        string border (N*2+1, '-');
        *(border.begin()) = '+';
        *(border.rbegin()) = '+';
        //
        cout << border <<'\n';
        for(int i = 0; i < N; i++) {
            cout << '|';
            for(int j = 0; j < N; j++) {
                if(i == j) cout << 'Y';
                else (cout << ( dfs(i, j) ? ('Y') : ('N') ) );
                cout << '|';
            }
            cout << '\n' << border << '\n';
        }
    }
}