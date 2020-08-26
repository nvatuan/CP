#include <bits/stdc++.h>
using namespace std;

int N;
set<int> S;

vector< pair<int, int> > V;

vector<int> maxleft;

vector<int> sol;

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) S.insert(i);
    maxleft.resize(N+2, 0);
    for(int i = 1; i <= N+1; i++) maxleft[i] = i-1;
    // --
    V.resize(N, pair<int, int> () );
    for(int a, i = 1; i <= N; i++) {
        cin >> a;
        V[i-1] = {a, i};
    }
    sort(V.begin(), V.end(), greater< pair<int, int> >());
    // --
    sol.resize(N, 0);
    for(int i = 0; i < N; i++) {
        // sol[N-1-i] =
        if(maxleft[V[i].first] == V[i].second) maxleft[V[i].first]--;
    }
    // --
    return 0;
}